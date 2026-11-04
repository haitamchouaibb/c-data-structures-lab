#include<stdio.h>
#include<stdlib.h>

#include"stack.h"


int main(void) {
    STACKinit(10);

    STACKpush(10);
    STACKpush(20);
    STACKpush(30);

    printf("\n--- TEST 1 ---\n");

    printf("Popped: %d\n", STACKpop());

    printf("\nRemaining elements:\n");
    STACKdisplay();
    printf("Element at the top : %d\n", STACKtop());

    return 0;
}
