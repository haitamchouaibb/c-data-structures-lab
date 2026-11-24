#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Item.h"
#include"ST.h"

int main(void){
    int maxN = 4;
    Item item;
    ST st = STinit(maxN);
    for (int i = 0; i < maxN; i++)
    {
        printf("Enter the items : \n");
        item = ITEMscan();
        STinsert(st,item);
    }
    STcount(st);
    STdisplay(st);
    

}