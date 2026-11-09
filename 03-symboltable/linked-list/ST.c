
#include <stdio.h>
#include <stdlib.h>
#include "ST.h"

typedef struct STnode *link;

struct STnode {
    Item val;
    link next;
};

typedef struct {
    link head;
    int size;
} list;

struct symboltable {
    list tab;
};

static link NEW(Item val, link next) {
    link x = malloc(sizeof(*x));

    if (x == NULL)
        return NULL;

    x->val = val;
    x->next = next;

    return x;
}

ST STinit(int maxN) {
    ST st = malloc(sizeof(*st));

    (void)maxN;

    if (st == NULL)
        return NULL;

    st->tab.head = NULL;
    st->tab.size = 0;

    return st;
}

void STfree(ST st) {
    link x, next;

    if (st == NULL)
        return;

    for (x = st->tab.head; x != NULL; x = next) {
        next = x->next;
        ITEMfree(x->val);
        free(x);
    }

    free(st);
}

int STcount(ST st) {
    if (st == NULL)
        return 0;

    return st->tab.size;
}

void STinsert(ST st, Item val) {
    link x, p, newNode;

    if (st == NULL || val == NULL)
        return;

    /* Caso 1: lista vuota o nuovo elemento prima della testa */
    if (st->tab.head == NULL ||
        KEYcompare(KEYget(val), KEYget(st->tab.head->val)) < 0) {

        newNode = NEW(val, st->tab.head);

        if (newNode == NULL)
            return;

        st->tab.head = newNode;
        st->tab.size++;
        return;
    }

    /* Caso 2: cerca la posizione corretta */
    p = st->tab.head;
    x = p->next;

    while (x != NULL &&
           KEYcompare(KEYget(val), KEYget(x->val)) >= 0) {
        p = x;
        x = x->next;
    }

    /* Evita di inserire due volte la stessa chiave */
    if (KEYcompare(KEYget(val), KEYget(p->val)) == 0) {
        ITEMfree(val);
        return;
    }

    newNode = NEW(val, x);

    if (newNode == NULL)
        return;

    p->next = newNode;
    st->tab.size++;
}

Item STsearch(ST st, Key k) {
    link x;
    int cmp;

    if (st == NULL || k == NULL)
        return NULL;

    for (x = st->tab.head; x != NULL; x = x->next) {
        cmp = KEYcompare(KEYget(x->val), k);

        if (cmp == 0)
            return x->val;

        /* La lista è ordinata: se superiamo k, possiamo fermarci */
        if (cmp > 0)
            break;
    }

    return NULL;
}

Item STselect(ST st, int r) {
    link x;
    int i = 0;

    if (st == NULL || r < 0 || r >= st->tab.size)
        return NULL;

    for (x = st->tab.head; x != NULL; x = x->next) {
        if (i == r)
            return x->val;

        i++;
    }

    return NULL;
}

void STdelete(ST st, Key k) {
    link x, p;

    if (st == NULL || k == NULL)
        return;

    p = NULL;

    for (x = st->tab.head; x != NULL; p = x, x = x->next) {
        int cmp = KEYcompare(KEYget(x->val), k);

        if (cmp == 0) {
            if (p == NULL)
                st->tab.head = x->next;
            else
                p->next = x->next;

            ITEMfree(x->val);
            free(x);
            st->tab.size--;
            return;
        }

        if (cmp > 0)
            return;
    }
}

void STdisplay(ST st) {
    link x;

    if (st == NULL)
        return;

    for (x = st->tab.head; x != NULL; x = x->next)
        ITEMshow(x->val);
}
