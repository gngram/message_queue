// gtklock
// Copyright (c) 2025 Ganga Ram

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Message {
    char *data;
    unsigned int len;
};

typedef void* MessageQ;

MessageQ init_message_q(int max_size);
void enqueue(MessageQ mq, struct Message *msg);
struct Message* dequeue(MessageQ mq);
void free_message_q(MessageQ mq);

