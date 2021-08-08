#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

typedef struct queue_t queue_t;


queue_t* newQueue(size_t queue_length, size_t item_size);
bool enqueue(queue_t* me, const void* item);
bool dequeue(queue_t* me, void* item);
bool queueIsFull(queue_t* me);
size_t getQueueSpace(queue_t* me);
void deleteQueue(queue_t* me);


#endif
