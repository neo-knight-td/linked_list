#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    printf("Here is a demo program for the implementation of the linked list :\r\n");

    List_t *pList = List_create();
    int firstListElem = 1;
    int secondListElem = 2;
    int thirdListElem = 3;
    int fourthListElem = 4;
    int fifthListElem = 5;

    printf("Pushing %d\r\n", firstListElem);
    List_push(pList, &firstListElem);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Inserting %d at position 1\r\n", secondListElem);
    List_insert(pList, &secondListElem, 1);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Pushing %d\r\n", thirdListElem);
    List_push(pList, &thirdListElem);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Inserting %d at position 2\r\n", fourthListElem);
    List_insert(pList, &fourthListElem, 2);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Pushing %d\r\n", fifthListElem);
    List_push(pList, &fifthListElem);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Size of the list is %d\r\n\r\n", List_getSize(pList));

    printf("Switching two first elements\r\n");
    List_t *pListElem = List_crawl(pList,1);
    List_switch(pList, pListElem);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Sorting the list\r\n");
    List_sort(pList);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Removing 2nd element from the list\r\n");
    List_remove(pList, 2);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Pop last element from the list\r\n");
    List_pop(pList);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Sorting the list\r\n");
    List_sort(pList);
    printf("Which gives : \r\n");
    List_display(pList);
    printf("\r\n");

    printf("Size of the list is %d\r\n\r\n", List_getSize(pList));

    List_remove(pList, 1);
    List_remove(pList, 1);
    List_remove(pList, 1);
    List_remove(pList, 1);

    printf("Size of the list is %d\r\n\r\n", List_getSize(pList));

    List_destroy(pList);

    return 0;
}