#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    printf("Here is a demo program for the implementation of the linked list :\r\n");

    List_t *pList = List_create();
    int firstListElem = 1;
    int *pFirstListElem = &firstListElem;
    int pushedListElem = 2;
    int *pPushedListElem = &pushedListElem;

    printf("Pushing %d\r\n", pushedListElem);
    List_push(pList, pPushedListElem);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Inserting %d\r\n", firstListElem);
    List_insert(pList, pFirstListElem, 1);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Size of the list is %d\r\n", List_getSize(pList));

    printf("Removing last element\r\n");
    List_remove(pList, 2);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    List_destroy(pList);

    return 0;
}