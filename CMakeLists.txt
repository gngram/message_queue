cmake_minimum_required(VERSION 3.10)

# Set project name and language
project(MQ4Thread C)

# Define the version (optional)
set(PROJECT_VERSION 1.0)

# Add the include directory for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Define the source files for the shared library
set(SOURCE_FILES
    src/message-queue.c
)

# Define the shared library target
add_library(messagequeue SHARED ${SOURCE_FILES})

# Define the source file for the test executable
set(TEST_FILES
    test/testapp.c
)

# Define the executable target
add_executable(testapp ${TEST_FILES})

# Link the shared library with the executable
target_link_libraries(testapp pthread messagequeue)
