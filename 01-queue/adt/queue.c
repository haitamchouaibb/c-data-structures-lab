#include<stdio.h>
#include<stdlib.h>

#include"queue.h"

typedef struct QUEUEnode *link; // Linked list NODE

struct QUEUEnode {
    Item val;
    link next;
};

struct queue { // QUEUE OBJECT
    link head;
    link tail;
};

static link NEW(Item val, link next){

    link x = malloc(sizeof *x);

    if (x == NULL)
    {
        fprintf(stderr,"Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    x->val = val;
    x->next = next;

    return x;
    
}

QUEUE QUEUEinit(int maxN){

    QUEUE q = malloc(maxN*(sizeof *q));

    if (q == NULL)
    {
        fprintf(stderr,"Queue memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    q->head = NULL;
    q->tail = NULL;

    return q;
    
}

int QUEUEempty(QUEUE q){ // Check if queue is empty
    return q->head == NULL;
}

void QUEUEput(QUEUE q, Item val){
    if (QUEUEempty(q)) {
        q->head  = NEW(val,NULL);
        q->tail = q->head;

        return;
    }

    q->tail->next = NEW(val, NULL);
    q->tail = q->tail->next;
}

Item QUEUEget(QUEUE q) {
    if (QUEUEempty(q))
    {
        fprintf(stderr,"Cannot remove from empty queue\n");
        exit(EXIT_FAILURE);
    }

    Item tmp = q->head->val;
    link t = q->head;
    free(q->head);
    q->head = t;

    if (q->head == NULL)
    {
        q->tail == NULL;
    }

    return tmp;

}

void QUEUEfree(QUEUE q){
    while (!QUEUEempty(q))
    {
        link t = q->head;
        q->head = q->head->next;

        free(t);
    }
    free(q);
}

void QUEUEdisplay(QUEUE q){
    link current;

    for(current = q->head; current != NULL; current = current ->next){
        printf("Current item %d\n", current->val);
    }
}

int QUEUEsize(QUEUE q){
    link current;
    int count = 0;
    for(current = q->head; current != NULL;current = current->next){
        count++;
    }
    printf("Total elements found in Queue : %d\n", count);
    return count;
}
