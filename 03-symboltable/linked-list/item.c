#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"

struct item {
    char name[MAXC];
    int num;
};

Item ITEMnew(){
    Item val = malloc(sizeof(*val));

    if (val == NULL)
    {
        return  NULL;
    }

    val->name[0] = '\0';
    val->num = 0;

    return val;
}

void ITEMfree(Item val){
    free(val);
}

Item ITEMscan(){
    Item val = ITEMnew();

    if (val == NULL)
    {
        return NULL;
    }

    if (scanf("%29s %d", val->name, &val->num) !=2) 
    {
        ITEMfree(val);
        return NULL;
    }

    return val;
}

void ITEMshow(Item val){
    if (val != NULL)
    {
        printf("%s %d\n", val->name, val->num);
    }
    
}

Key KEYget(Item val){
    return val->name;
}

int KEYcompare(Key k1,Key k2){
    return strcmp(k1,k2);
}

int ITEMcheckvoid(Item val){
    return val == NULL || val->name[0] == '\0';
}

Item ITEMsetvoid(){
    return ITEMnew();
}