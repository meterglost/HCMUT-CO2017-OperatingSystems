#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (q->size < MAX_QUEUE_SIZE) {
		q->proc[q->size++] = proc;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose priority is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	struct pcb_t * proc = NULL;
	if (!empty(q)) {
		int maxIndex = 0;
		for (int i = 0; i < q->size; i++) {
			if (q->proc[i]->priority > q->proc[maxIndex]->priority) {
				maxIndex = i;
			}
		}
		proc = q->proc[maxIndex];
		q->size--;
		for (int i = maxIndex; i < q->size; i++) {
			q->proc[i] = q->proc[i + 1];
		}
	}
	return proc;
}

