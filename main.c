#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "process.h"
#include "ready-queue.h"


int main() {
	queue q;
	init_queue(&q);

	process p1, p2, p3;
	init_process(&p1, 12);
	init_process(&p2, 18);
	init_process(&p3, 34);

	enqueue(&q, p1);
	enqueue(&q, p2);
	enqueue(&q, p3);

	display_queue(&q);

	process out;
	dequeue(&q, &out);

	display_queue(&q);
	printf("Dequeue value: P%d\n", out.pid);

	free_queue(&q);
	exit(0);
}
	
