#include<stdio.h>
#include<stdlib.h>

#include"stack.h"

typedef struct STACKnode *link;

struct STACKnode{
    Item val;
    link next;
};

static link head = NULL;

void STACKinit(maxN) {
    (void) maxN;
    head = NULL;
}

void STACKpush(Item val) {
    link newNode = malloc(sizeof*newNode);

    if (newNode == NULL)
    {
        fprintf(stderr,"Memory allocaiton failed\n");
    }

    newNode->val = val;
    newNode->next = head;

    head = newNode;
    
}

Item STACKpop() {
    if (head == NULL)
    {
        fprintf(stderr,"Stack is  empty\n");
    }
    Item tmp = head->val;
    link t = head->next;
    free(head);
    head = t;
    return tmp;
}

void STACKdisplay(){
    link current = head;

    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
    
}

Item STACKtop(void){
    return head->val;
}