#include<stdio.h>
#include<stdlib.h>

#include"queue.h"

int main() {
    QUEUE q = QUEUEinit(5);

    QUEUEput(q,10);

    printf("Queue : %d\n", QUEUEget(q));
}