#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Queue {
  int* queue;
  int front, rear, size, capacity;
};

struct Queue* create_queue(int);
void enqueue(struct Queue*, int);
int dequeue(struct Queue*);
void printQueueElements(struct Queue*);

int main() {
  struct Queue* queue = create_queue(50);

  char operation[20];  // ENQUEUE, DEQUEUE, EXIT
  int value;

  scanf("%s %d", &operation, &value);
  while (strcmp(operation, "EXIT")) {
    if (strcmp(operation, "ENQUEUE") == 0) {
      enqueue(queue, value);
    } else if (strcmp(operation, "DEQUEUE") == 0) {
      dequeue(queue);
    }

    scanf("%s %d", &operation, &value);
  }
}

struct Queue* create_queue(int capacity) {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->front = -1;
  queue->rear = -1;
  queue->size = 0;
  queue->capacity = capacity;
  queue->queue = (int*)malloc(capacity * sizeof(int));

  return queue;
}

void enqueue(struct Queue* queue, int node) {
  if (queue->size == queue->capacity) {
    return;
  }

  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->queue[queue->rear] = node;
  queue->size = queue->size + 1;

  if (queue->front == -1) {
    queue->front = 0;
    fflush(stdout);
  }

  printQueueElements(queue);
}

int dequeue(struct Queue* queue) {
  if (queue->size == 0) {
    return INT_MIN;
  }

  int node = queue->queue[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;

  if (queue->size == 0) {
    queue->front = -1;
    queue->rear = -1;
  }

  printQueueElements(queue);
  return node;
}

void printQueueElements(struct Queue* queue) {
  int counter = 0;
  for (int i = queue->front; counter++ < queue->size;
       i = (i + 1) % queue->capacity) {
    printf("%d ", queue->queue[i]);
    fflush(stdout);
  }
  printf("\n");
  fflush(stdout);
}
