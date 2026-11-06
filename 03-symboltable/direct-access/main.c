#include<stdio.h>
#include<stdlib.h>

#include"ST.h"

int main(void){
    ST st;
    Item val;

    st = STinit(26);

    if (st == NULL) {
        fprintf(stderr, "could not initialize symbol table\n");
        return 1;
    }
    
    printf("Enter three items (single uppercase letter and number):\n");
    for (int i = 0; i < 3; i++)
    {
        val = ITEMscan();

        if (val==NULL)      
        {
            printf("input error \n");
            STfree(st);
            return 1;
        }

        STinsert(st, val);
        
    }

    printf("SYmbol table : \n");
    STdisplay(st);

    STfree(st);
    return 0;
    
}