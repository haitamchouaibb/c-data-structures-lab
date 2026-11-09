#ifndef ITEM_H
#define ITEM_H

#define MAXC 30

typedef struct item *Item;
typedef char *Key;

Item ITEMnew();
void ITEMfree(Item val);
Item ITEMscan();
void ITEMshow(Item val);

Key KEYget(Item val);
int KEYcompare(Key k1,Key k2);

int ITEMcheckvoid(Item val);
Item ITEMsetvoid();

#endif
