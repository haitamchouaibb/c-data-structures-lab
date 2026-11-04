#include<stdio.h>
#include<stdlib.h>

#include"stack.h"

int main(void){
    STACK s = STACKinit();
    STACKpush(s,10);
    STACKdisplay(s);
    STACKpush(s,20);
    STACKpop(s);
    STACKdisplay(s);
    return 0;
}