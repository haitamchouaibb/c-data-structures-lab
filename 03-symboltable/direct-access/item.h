#ifndef ITEM_H
#define ITEM_H
#define MAXC 30

/* --- ADT I° CLASSE --- */
typedef struct item *Item;
typedef char *Key;

/* --- KEY --- */
Key KEYget(Item val);
Key KEYscan();
int KEYcompare(Key k1, Key k2);

/* --- ITEM --- */
Item ITEMnew();
void ITEMfree(Item val);
Item ITEMscan();
void ITEMshow(Item val);
int ITEMless(Item val1, Item val2);
int ITEMgreater(Item val1, Item val2);
int ITEMcheckvoid(Item val);
Item ITEMsetvoid();

#endif