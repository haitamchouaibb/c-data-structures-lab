#include<stdio.h>
#include<stdlib.h>

#include"queue.h"

int main() {
    QUEUE q = QUEUEinit(5);

    QUEUEput(q,10);
    QUEUEput(q,20);
    QUEUEdisplay(q);
    QUEUEsize(q);
}