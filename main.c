#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "process.h"
#include "ready-queue.h"


int main() {
	queue q;
  	init_queue(&q);

  	process p1, p2, p3;
  	init_process(&p1, 12, 0, 8, 2);   // PID=12, arrival=0, burst=8, priority=2
  	init_process(&p2, 18, 1, 4, 1);   // PID=18, arrival=1, burst=4, priority=1
  	init_process(&p3, 34, 2, 9, 3);   // PID=34, arrival=2, burst=9, priority=3

  	enqueue(&q, p1);
  	enqueue(&q, p2);
  	enqueue(&q, p3);

  	display_queue(&q);

  	free_queue(&q);
  	return 0;
	
}
	
