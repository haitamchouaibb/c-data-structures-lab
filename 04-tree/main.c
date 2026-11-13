#include<stdio.h>
#include<stdlib.h>

#include"BST.h"

int main(void){
    BST bst = BSTinit();

    int n;

    printf("Quanti elementi vuoi inserire : \n");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("input non valido\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Inserisci nome e numero : ");

        Item item = ITEMscan();

        if (item == NULL)
        {
            printf("Errore durante la lettura\n");
            exit(EXIT_FAILURE);
        }

        BSTinsert_leafR(bst, item);

        
    }

    printf("\nElementi del BST in ordine crescente : \n");
    BSTvisit(bst);

    printf("\n Quale chiave vuoi cercare ? : ");
    char buffer[100];
    scanf("%99s", buffer);
    Key key = buffer;
    Item found = BSTsearch(bst,key);

    if (found != NULL)
    {
        printf("Elemento trovato ! \n");
        ITEMshow(found);
        printf("\n");
    } else{
        printf("Elemento non trovato.\n");
    }
    
    BSTfree(bst);

    return EXIT_SUCCESS;
    
    
}