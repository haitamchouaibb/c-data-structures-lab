#ifndef BST_H
#define BST_H

#include "item.h"

typedef struct binarysearchtree *BST;

BST BSTinit(void);
void BSTfree(BST bst);

int BSTcount(BST bst);
int BSTempty(BST bst);

Item BSTsearch(BST bst,Key k);
Item BSTmin(BST bst);
Item BSTmax(BST bst);

void BSTinsert_leafR(BST bst, Item item);

void BSTvisit(BST bst);

#endif