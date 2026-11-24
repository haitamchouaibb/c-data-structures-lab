#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ST.h"
#include"Item.h"

typedef struct STnode* link;
struct STnode{ Item item; link next};

struct symbtab{
    link *heads;
    int N;
    int M;
    link z;
};

static link NEW(Item item, link next);
static int STsizeSet(int maxN, int r);
static int hash(Key v, int M);

static link NEW(Item item, link next){
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}

ST STinit(int maxN){
    int i,r;
    
    ST st = malloc(sizeof(*st));

    if (st == NULL)
    {
        printf("Memory allocation error \n");
        return NULL;
    }
    printf("Enter desired average list length : ");
    scanf("%d", &r);

    st->N = 0;
    st->M = STsizeSet(maxN,r);
    st->heads = malloc(st->M*sizeof(link));
    st->z = NEW(ITEMsetNull(),NULL);

    for ( i = 0; i < st->M; i++)
    {
        st->heads[i] = st->z;
    }
    return st;
}