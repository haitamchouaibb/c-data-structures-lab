#ifndef STACK_H
#define STACK_H

typedef int Item;

typedef struct stack *STACK;

STACK STACKinit(void);
int STACKempty(STACK s);
void STACKpush(STACK s,Item val);
Item STACKpop(STACK s);
Item STACKtop(STACK s);
void STACKdisplay(STACK s);
void STACKfree(STACK s);

#endif