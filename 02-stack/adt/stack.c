#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

typedef struct STACKnode *link;

struct STACKnode{
    Item val;
    link next;
};
struct stack {
    link head;
};

STACK STACKinit(void){
    STACK s = malloc(sizeof*s);

    s->head = NULL;

    return s;
    
}

void STACKpush(STACK s, Item val){
    link tmp = malloc(sizeof(link));
    tmp->val = val;
    tmp->next = s->head;
    s->head = tmp;

    printf("Element pushed : %d\n", val);
}

void STACKdisplay(STACK s){
    link current;

    for(current = s->head;current != NULL;current = current->next){
        printf("Current element : %d\n", current->val);
    }
}

Item STACKpop(STACK s){
    if (s->head == NULL)
    {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    Item value = s->head->val;

    link tmp = s->head; // Serve per non perdere il link tra head e head->next
    s->head = s->head->next;
    free(tmp);

    return s->head->val;
    
}


