#pragma once
#include "process.h"

typedef struct node {
	process data;
	struct node *next;
} node;

typedef struct queue {
	node *tail;
	node *head;
} queue;

void init_queue(queue *q);

void free_queue(queue *q);

int enqueue(queue *q, process p);

int dequeue(queue *q, process *p);

void display_queue(queue *q);

