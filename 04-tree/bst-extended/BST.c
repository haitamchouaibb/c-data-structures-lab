#include<stdio.h>
#include<stdlib.h>

#include "BST.h"

typedef struct BSTnode *link;

struct BSTnode{
    Item item;
    link p;
    link l;
    link r;
    int N
};

struct binarysearchtree{
    link root;
    link z;
};

static link NEW(Item item,link p, link l, link r){
    link x = malloc(sizeof *x);

    if (x == NULL)
    {
        fprintf(stderr,"Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    x->item = item;
    x->p = p;
    x->l = l;
    x->r = r;
    x->N = 1;

    return x;
    
}

static void fixN(link h,link z){
    if (h != z)
        h->N = 1 + h->l->N + h->r->N;
}

static int compare(Item a, Item b){
    return KEYcompare(KEYget(a),KEYget(b));
}

BST BSTinit(void){
    BST bst = malloc(sizeof(*bst));

    if (bst == NULL)
    {
        fprintf(stderr,"Memory allocatio problem\n");
        exit(EXIT_FAILURE);
    }

    bst->z->item = NULL;
    bst->z->p = bst->z;
    bst->z->l = bst->z;
    bst->z->r = bst->z;
    bst->z->N = 0;

    bst->root = bst->z;

    return bst;
    
}

static void freeR(link h,link z){
    if (h == z)
    {
        return;
    }
    
    freeR(h->l,z);
    freeR(h->r,z);
    ITEMfree(h->item);
    free(h);
}

void BSTfree(BST bst){
    if (bst == NULL)
    {
        return;
    }

    freeR(bst->root, bst->z);
    free(bst->z);
    free(bst);
    
}

int BSTcount(BST bst){
    if (bst == NULL)
    {
        return 0;
    }

    return bst->root->N;
    
}

int BSTempty(BST bst){
    return bst == NULL || bst->root == bst->z;
}

Item BSTsearch(BST bst, Key key){
    if (bst == NULL || key == NULL)
    {
        return NULL;
    }

    link h = bst->root;

    while (h != bst->z)
    {
        int cmp = KEYcompare(key, KEYget(h->item));

        if (cmp == 0)
        {
            return h->item;
        }

        if(cmp < 0) {
            h = h->l;
        } else {
            h = h->r;
        }
        
    }
    
    return NULL;
}

Item BSTmin(BST bst){
    if (BSTempty(bst))
    {
        return NULL;
    }

    link h = bst->root;

    while ( h->l != bst->z) { // Per trovare il minimo itero sui figli sinistri che sono sempre minori
        h = h->l;
    }

    return h->item;
    
}

Item BSTmax(BST bst){
    if (BSTempty(bst))
    {
        return NULL;
    }

    link h = bst->root;

    while ( h->r != bst->z) { // Per trovare il minimo itero sui figli sinistri che sono sempre minori
        h = h->r;
    }

    return h->item;
    
}

static link insertR(link h,link p, link z,Item item){
    if (h == z)
    {
        return NULL;
    }

    if(compare(item,h->item)<0) 
        h->l = insertR(h->l,h,z,item);
    else
        h->r = insertR(h->r,h,z,item);

    fixN(h, z);
    return h;
    
}

void BSTinsert_leafR(BST bst, Item item){
    if (bst == NULL || item == NULL)
    {
        return;
    }

    if(BSTsearch(bst,KEYget(item)) != NULL) {
        ITEMfree(item); return ;}

    bst->root = insertR(bst->root,bst->z,bst->z,item);
    bst->root->p = bst->z;
    
}

void BSTinsert_leafI(BST bst, Item item){
    if (bst == NULL || item == NULL)
    {
        return ;
    }

    if (BSTsearch(bst, KEYget(item))!= NULL)
    {
        ITEMfree(item);
        return;
    }

    link h = bst->root;
    link p = bst->z;

    while (h != bst->z)
    {
        p = h;
        h->N++;
        if (compare(item, h->item) < 0)
        {
            h = h->l;
        } else {
            h = h->r;
        }


        
    }

    h = NEW(item, p ,bst->z,bst->z);

    if (p == bst->z)
    {
        bst->root = h;
    } else if 
        (compare(item,p->item) < 0)
            p->l = h;
            else p->r = h;
}

static void visitR(link h, link z, int strategy){
    if (h == z)
    {
        return;
    }

    if(strategy == PREORDER){
        ITEMshow(h->item);
        printf("\n");
    }

    visitR(h->l,z,strategy);

    if (strategy == INORDER)
    {
        ITEMshow(h->item);
        printf("\n");
    }

    visitR(h->r,z,strategy);

    if (strategy == POSTORDER)
    {
        ITEMshow(h->item);
        printf("\n");
    }
    
    
    
}

void BSTvisit(BST bst, int strategy){
    if (bst == NULL)
    {
        return;
    }

    if (strategy < PREORDER || strategy > POSTORDER)
    {
        return;
    }

    visitR(bst->root,bst->z,strategy);
    
    
}

static link rotR(link h, link z){
    link x = h->l;
    link p = h->p;

    h->l = x->r;

    if (x->r != z)
    {
        x->r->p = h;
    }

    x->r = h;
    h->p = x;
    x->p = p;
    x->N = h->N;
    fixN(h, z);

    return x;
    
}

static link rotL(link h, link z) {
    link x = h->r;
    link p = h->p;

    h->r = x->l;

    if (x->l != z)
    {
        x->l->p = h;
    }

    x->l = h;
    h->p = x;
    x->p = p;

    x->N = h->N;
    fixN(h, z);

    return x;
    
}