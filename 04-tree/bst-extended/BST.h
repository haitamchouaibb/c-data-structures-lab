#ifndef BST_H
#define BST_H

#include "item.h"

typedef struct binarysearchtree *BST;

#define PREORDER 0
#define INORDER 1
#define POSTORDER 2

BST BSTinit(void);
void BSTfree(BST bst);

int BSTcount(BST bst);
int BSTempty(BST bst);

Item BSTsearch(BST bst, Key k);
Item BSTmin(BST bst);
Item BSTmax(BST bst);
Item BSTsucc(BST bst, Key key);
Item BSTpred(BST bst,Key key);
Item BSTselect(BST bst,int r);

void BSTinsert_leafI(BST bst, Item item);
void BSTinsert_leafR(BST bst, Item item);
void BSTinsert_root(BST bst, Item item);

void BSTdelete(BST bst, Key key);
void BSTvisit(BST bst, int strategy);

void BSTbalance(BST bst);

#endif