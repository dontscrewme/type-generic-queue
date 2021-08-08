#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

struct queue_t
{
	uint8_t head;
	uint8_t tail;
	uint8_t space;
	uint8_t queue_length;
	uint8_t item_size;
	uint8_t data[];
};


queue_t* newQueue(size_t queue_length, size_t item_size)
{
	queue_t* me = malloc(sizeof(queue_t) + queue_length*item_size);
	if (!me)
	{
		return NULL;
	}

	me->head = 0;
	me->tail = 0;
	me->space = queue_length;

	me->item_size = item_size;
	me->queue_length = queue_length;
	memset(me->data, 0, item_size*queue_length);

	return me;
}


bool enqueue(queue_t* me, const void* item)
{
	if ((!me) || (0 == me->space))
	{
		return false;
	}

	memcpy(&me->data[me->tail*me->item_size], item, me->item_size);
	me->tail = (me->tail+1) % me->queue_length;
	--me->space;

	return true;
}


bool dequeue(queue_t* me, void* item)
{
	if ((!me) || (me->queue_length == me->space))
	{
		return false;
	}

	memcpy(item, &me->data[me->head*me->item_size], me->item_size);
	me->head = (me->head+1) % me->queue_length;
	++me->space;
	
	return true;
}

bool queueIsFull(queue_t* me)
{
	if (0 == me->space)
	{
		return true;
	}
	
	return false;
}


bool queueIsEmpty(queue_t* me)
{
	if (me->space == me->queue_length)
	{
		return true;
	}

	return false;
}

size_t getQueueSpace(queue_t* me)
{
	return me->space;
}

void deleteQueue(queue_t* me)
{
	free(me);
}
