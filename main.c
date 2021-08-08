#include <stdio.h>
#include <stdint.h>
#include "queue.h"

int main(void) {

  /*example 1*/
  queue_t* IntQueue = newQueue(3, sizeof(int));

  int x = 1;
  int y = 2;
  int z = 3;

  enqueue(IntQueue, &x);
  enqueue(IntQueue, &y);
  enqueue(IntQueue, &z);

  dequeue(IntQueue, &z);
  printf("z = %d\n", z);
  
  dequeue(IntQueue, &y);
  printf("y = %d\n", y);

  dequeue(IntQueue, &x);
  printf("x = %d\n", x);

  printf("\n");


  /*example 2*/
#define STRING_SIZE 10
  queue_t* stringQueue = newQueue(2, STRING_SIZE);

  char first[10] = "Andy";
  char last[10] = "Lin";

  enqueue(stringQueue, &first);
  enqueue(stringQueue, last);

  dequeue(stringQueue, &last);
  printf("last = %s\n", last);

  dequeue(stringQueue, &first);
  printf("first = %s\n", first);

  return 0;
}


