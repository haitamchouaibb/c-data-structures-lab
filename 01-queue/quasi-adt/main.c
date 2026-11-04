#include<stdio.h>

#include"queue.h"

int main(void) {
    QUEUEinit(10);

    printf("Is Queue emty ? %d\n", QUEUEempty());

    QUEUEput(10);
    QUEUEput(20);
    QUEUEput(30);

    printf("First element : %d\n", QUEUEget());
    printf("Second element : %d\n", QUEUEget());

    QUEUEput(40);

    printf("Third element : %d\n", QUEUEget());
    printf("Fourth element : %d\n", QUEUEget());

    printf("Is Queue empty ? %d\n", QUEUEempty());

    for(int i = 0 ; i< 10;i++){
        QUEUEput(i);
        printf("Cycling through the queue : %d\n", QUEUEget());
    }

    QUEUEfree();



    return 0;
}