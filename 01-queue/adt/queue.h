#ifndef QUEUE_H
#define QUEUE_H

typedef int Item;
typedef struct queue *QUEUE; // This allows to manage multiple independent Queues

QUEUE QUEUEinit(int maxN);
int QUEUEempty();
void QUEUEput(QUEUE q, Item val);
Item QUEUEget(QUEUE q);
void QUEUEfree(QUEUE q);

#endif