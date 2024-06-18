#include <stdio.h>
#include <stdint.h>
#include "queue.h"

#define MAX 5

struct person {
  int age;
  int height;
  int weight;
};

void testQueue() {
  queue_t* q = newQueue(MAX, sizeof(struct person));  

  struct person p1;
  for (int i=0; i<MAX; i++) {
    p1.age = i;
    p1.height = i;
    p1.weight = i;
    assert(enqueue(q, &p1) == true);
  }

  
  for (int i = 0; i < 5; i++) {
    assert(dequeue(q, &p1) == true);
    assert(p1.age == i);
    assert(p1.height == i);
    assert(p1.weight == i);
    
  }

  assert(dequeue(q, &p1) == false);

  for (int i = 0; i < 5; i++) {
    p1.age = i;
    p1.height = i;
    p1.weight = i;
    assert(enqueue(q, &p1) == true);
  }
  assert(enqueue(q, &p1) == false);

  deleteQueue(q);
}


int main(void) {

  testQueue();

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

  deleteQueue(IntQueue);
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

  deleteQueue(stringQueue);
  return 0;
}
