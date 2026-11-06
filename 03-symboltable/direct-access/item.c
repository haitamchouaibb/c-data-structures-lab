#include "item.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* --- ADT I° CLASSE --- */

/* TIPO 3 */
struct item {
    char name[MAXC];
    int num;
};

Item ITEMnew(void) {
    Item val = (Item) malloc(sizeof(struct item));
    
    if (val == NULL)
        return NULL;
    val->name[0] = '\0';
    val->num = 0;

    return val;
}

void ITEMfree(Item val) {
    free(val);
}

Item ITEMscan() {
    Item val = ITEMnew();

    if (val == NULL)
        return NULL;

    if (scanf("%29s %d", val->name, &val->num) != 2) {
        ITEMfree(val);
        return NULL;
    }
    
    return val;
}

/* FUNZIONI COMUNI */
Key KEYget(Item val) {
    return (val->name);
}

int KEYcompare (Key k1, Key k2) {
    return (strcmp(k1, k2));
}

void ITEMshow(Item val) {
    printf("%s %d", val->name, val->num);
}

int ITEMless(Item val1, Item val2) {
    return (strcmp(KEYget(val1), KEYget(val2)) < 0);
}

int ITEMgreater(Item val1, Item val2) {
    return (strcmp(KEYget(val1), KEYget(val2)) > 0);
}

Item ITEMsetvoid() {
    Item val = ITEMnew();

    if (val == NULL)
        return NULL;

    return val;
}

int ITEMcheckvoid(Item val) {
    if (val == NULL)
        return 1;

    return val->name[0] == '\0';
}