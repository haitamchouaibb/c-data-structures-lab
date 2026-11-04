#ifndef    QUEUE_H
#define QUEUE_H

typedef int Item;

void QUEUEinit(int maxN);
int QUEUEempty(void);
void QUEUEput(Item val);
Item QUEUEget(void);
void QUEUEfree(void);

#endif