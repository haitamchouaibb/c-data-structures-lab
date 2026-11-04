#ifndef STACK_H
#define STACK_H

typedef int Item;

void STACKinit(int maxN);
int STACKempty(void);
void STACKpush(Item val);
Item STACKpop();
Item STACKtop();
void STACKfree();
void STACKdisplay();

#endif