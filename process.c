#include "process.h"

int init_process(process *p, unsigned int pid) {
	p->pid = pid;
	p->memory_given = FALSE;
}

