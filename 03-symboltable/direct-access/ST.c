#include<stdio.h>
#include<stdlib.h>

#include"ST.h"

struct symboltable{
    Item *a;
    int N;
    int M;
};

static int GETindex(Key k){
    if (k == NULL || k[0] < 'A' || k[0] > 'Z' || k[1] != '\0')
    {
        return -1;
    }

    return k[0] - 'A';
    
}

ST STinit(int maxN){
    ST st;
    int i;

    if (maxN <= 0 )
    {
        return NULL;
    }

    st = malloc(sizeof(*st));

    if (st == NULL)
    {
        return NULL;
    };

    st->a = malloc(maxN * sizeof(Item));

    if (st->a == NULL) {
        free(st);
        return NULL;
    }

    for ( i = 0; i < maxN; i++)
    {
        st->a[i] = ITEMsetvoid();

        if(st->a[i] == NULL){
            while (i > 0)
                ITEMfree(st->a[--i]);
            free(st->a);
            free(st);
            return NULL;
        }
    }

    st->M = maxN;
    st->N = 0;

    return st;
}

int STcount(ST st){
    return st->N;
}

void STfree(ST st){
    int i;

    if (st == NULL)
        return;

    for ( i = 0; i < st->M; i++)
        ITEMfree(st->a[i]);

    free(st->a);
    free(st);
}

void STinsert(ST st, Item val) {
    int index;

    if (st == NULL || val == NULL)
        return;

    index = GETindex(KEYget(val));

    if (index < 0 || index >= st->M)
        return;

    if (ITEMcheckvoid(st->a[index]))
        st->N++;
    else if (st->a[index] != val)
        ITEMfree(st->a[index]);

    st->a[index] = val;
}

Item STsearch(ST st,Key k){
    int index;

    if (st == NULL)
    {
        return ITEMsetvoid();
    }

    index = GETindex(k);

    if(index <0 || index>= st->M){
        return ITEMsetvoid();
    }

    return st->a[index];
    
}

void STdelete(ST st,Key k){
    int index;

    if (st == NULL)
        return;

    index = GETindex(k);

    if (index < 0 || index >= st->M)
        return;

    if(!ITEMcheckvoid(st->a[index])){
        ITEMfree(st->a[index]);
        st->a[index] = ITEMsetvoid();

        if(st->a[index] != NULL){
            st->N--;
        }
    }
}

Item STselect(ST st, int r ){ // Select the r-th stored item
    int i;

    if (st == NULL || r < 0)
        return ITEMsetvoid();

    for ( i = 0; i < st->M; i++)
    {
        if (!ITEMcheckvoid(st->a[i]) && r-- == 0)
            return st->a[i];
    }

    return ITEMsetvoid();
    
}

void STdisplay(ST st){
    int i;

    if (st == NULL)
        return;

    for ( i = 0; i < st->M; i++)
    {
        if (!ITEMcheckvoid(st->a[i])) {
            ITEMshow(st->a[i]);
            printf("\n");
        }
    }
}
