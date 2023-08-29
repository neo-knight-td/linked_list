#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    printf("Hello World\r\n");

    List_t *pList = List_create();
    int firstListElem = 1;
    int *pFirstListElem = &firstListElem;
    int pushedListElem = 2;
    int *pPushedListElem = &pushedListElem;

    List_push(pList, pPushedListElem);
    List_display(pList);

    List_insert(pList, pFirstListElem, 1);
    List_display(pList);

    List_remove(pList, 2);
    List_display(pList);

    List_destroy(pList);

    return 0;
}