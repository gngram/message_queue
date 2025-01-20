#include "message-queue.h"
#include <pthread.h>
#include <string.h>

#define  NUMTX 4  // Number of transactions between threads

void* thread_enqueue(void *arg) {
    MessageQ mq = (MessageQ) arg;
    struct Message *msg;

    char m1[NUMTX][15] = {"Message1", "Message2", "Message3", "Message4"};

    for (int i = 0; i < NUMTX; i++) {
      msg = malloc(sizeof(struct Message));
      msg->data = strdup(m1[i]);
      msg->len = strlen(msg->data) + 1;
      printf("[Sender Thread] sending: %s\n", msg->data);
      enqueue(mq, msg);
    }
    
    printf("[Sender Thread] sending: NULL (TERM)\n");
    enqueue(mq, (struct Message*)0);

    return NULL;
}

int main() {
    MessageQ mq = init_message_q(2); //Queue length 2
    if (mq == NULL) {
        fprintf(stderr, "Failed to initialize message queue.\n");
        return 1;
    }

    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, thread_enqueue, mq) != 0) {
        fprintf(stderr, "Failed to create thread.\n");
        free_message_q(mq);
        return 1;
    }

    while (1) {
      struct Message* received_msg = dequeue(mq);
      if (received_msg != NULL) {
          printf("[Main Thread]: Received %s\n", received_msg->data);
          free(received_msg->data);
          free(received_msg);
      } else {
          printf("[Main Thread]: NULL (TERM) received. Exiting...\n");
          break;
      }
    }

    pthread_join(thread_id, NULL);
    free_message_q(mq);

    return 0;
}
