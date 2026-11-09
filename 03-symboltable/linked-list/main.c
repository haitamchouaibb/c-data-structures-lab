#include <stdio.h>
#include "ST.h"

int main(void) {
    ST st = STinit(100);
    Item val;
    int i;

    if (st == NULL) {
        printf("Initialization failed\n");
        return 1;
    }

    printf("Enter three items (name number):\n");

    for (i = 0; i < 3; i++) {
        val = ITEMscan();

        if (val == NULL) {
            STfree(st);
            return 1;
        }

        STinsert(st, val);
    }

    printf("\nSymbol Table:\n");
    STdisplay(st);

    printf("\nCount: %d\n", STcount(st));

    printf("\nSearch B:\n");
    val = STsearch(st, "B");

    if (val != NULL)
        ITEMshow(val);
    else
        printf("Item not found\n");

    STdelete(st, "B");

    printf("\nAfter deleting B:\n");
    STdisplay(st);

    printf("\nCount: %d\n", STcount(st));

    STfree(st);
    return 0;
}