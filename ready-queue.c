#include "ready-queue.h"

void init_queue(queue *q) {
	q->tail = NULL;
	q->head = NULL;
}

int is_empty(queue *q) {
	return q->head == NULL;
}

int enqueue(queue *q, process p) {
	if (!p.memory_given) {
		printf("Memory not given to process");
		return 0;
	}

	node *new_node = malloc(sizeof(node));
	new_node->data = p;
	new_node->next = NULL;

	if (q->tail == NULL) {
		q->head = q->tail = new_node;
		return 1;
	}

	q->tail->next = new_node;
	q->tail = new_node;
	return 1;
}

int dequeue(queue *q) {
	if (is_empty(q)) {
		return 0;
	}

	node *tmp = q->head;

	q->head = q->head->next;
	if (q->head == NULL) {
		q->tail = NULL;
	}

	free(tmp);
	return 1;
}

void display_queue(queue *q) {
	node *tmp = q->head;
	while (tmp != NULL) {
		printf("P%u ", tmp->data.pid);
		tmp = tmp->next;
	}
	printf("\n");
}
