#include<stdio.h>
#include<stdlib.h>

#include"queue.h"

typedef struct QUEUEnode *link;

struct QUEUEnode{
    Item val;
    link next;
};

static link head = NULL;
static link tail = NULL;

static link NEW(Item val, link next) { // Create a new node
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

void QUEUEinit(int maxN) {
    (void) maxN;

    head = NULL;
    tail = NULL;
}

int QUEUEempty(void) {
    return head == NULL;
}

void QUEUEput(Item val){
    if (QUEUEempty())
    {
        head = tail = NEW(val, NULL);

        return;
    }

    tail->next = NEW(val, NULL);
    tail = tail->next;
    
}

Item QUEUEget(void) {
    if (QUEUEempty())
    {
        fprintf(stderr,"Cannot remove from an empty queue\n");
        exit(EXIT_FAILURE);
    }

    Item tmp = head->val;
    link t = head->next;

    free(head);
    head = t;

    if (head == NULL)
    {
        tail = NULL;
    }
    
    return tmp;
    
}

void QUEUEfree(void) {
    while (!QUEUEempty())
    {
        link t = head;
        head = head->next;
        free(t);
    }

    tail = NULL;
    
}

