#include<stdio.h>
#include<stdlib.h>

#include"BST.h"

typedef struct BSTnode *link;

struct BSTnode{ // Rappresenta un solo nodo
    Item item;
    link right;
    link left;
};

struct binarysearchtree{ // Rappresenta l'intero albero
    link root;
    link z; // Nodo SENTINELLA : quando un figlio punta a z significa che quel ramo è vuoto
};

static link NEW(Item item,link left,link right){
    link x = malloc(sizeof *x);

    if (x==NULL)
    {
        fprintf(stderr,"Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    x->item = item;
    x->left = left;
    x->right = right;

    return x;
}

BST BSTinit(void){
    BST bst = malloc(sizeof(*bst));

    if (bst==NULL)
    {
        fprintf(stderr,"Memory allocation problem\n");
        exit(EXIT_FAILURE);
    }

    bst->z = malloc(sizeof(*bst->z));
    if (bst->z == NULL)
    {
        fprintf(stderr,"Memory allocation problem for sentinel\n");
        free(bst);
        exit(EXIT_FAILURE);
    }

    bst->z->item = NULL;
    bst->z->left = bst->z;
    bst->z->right = bst->z;

    bst->root = bst->z; // Albero completamente vuoto

    return bst;
}

static link insertR(link h, link z, Item item){ // h : nodo corrente
    if (h == z)
    {
        return NEW(item, z, z);
    }

    int cmp = KEYcompare(KEYget(item), KEYget(h->item));
    if (cmp < 0)
    {
        h->left = insertR(h->left, z, item);
    }
    else if (cmp > 0)
    {
        h->right = insertR(h->right, z, item);
    }

    return h;
}

void BSTinsert_leafR(BST bst,Item item){
    if (bst == NULL || item == NULL)
    {
        return;
    }

    bst->root = insertR(bst->root, bst->z, item);
}

Item BSTsearch(BST bst,Key key){
    if (bst == NULL || key == NULL)
    {
        return NULL;
    }

    link h = bst->root;

    while(h != bst->z){
        int cmp = KEYcompare(key,KEYget(h->item));
        if (cmp == 0)
        {
            return h->item;
        }

        if (cmp < 0)
        {
            h=h->left;
        } else {
            h = h->right;
        }
        
        
    }
    return NULL;
    
}

static void visitR(link h,link z){
    if (h==z)
    {
        return;
    }
    visitR(h->left,z);
        ITEMshow(h->item);
        printf("\n");
        visitR(h->right,z);
}

void BSTvisit(BST bst){
    if (bst == NULL)
    {
        return;
    }

    visitR(bst->root,bst->z);
}

static void freeR(link h,link z){
    if (h==z)       
    {
        return ;
    }
    freeR(h->left,z);
    freeR(h->right,z);

    ITEMfree(h->item);
    free(h);
    
}
void BSTfree(BST bst){
    if (bst==NULL)
    {
        return ;
    }

    freeR(bst->root,bst->z);

    free(bst->z);
    free(bst);
    
}


