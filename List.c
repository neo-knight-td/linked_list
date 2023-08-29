#include <stdio.h>
#include <stdlib.h>
#include "List.h"

List_t *Element_create(void* pParamPrevElem,void* pParamNextElem, void* pParamItem){

    //allocate memory for the new list element
    List_t *pList = (List_t*) malloc(sizeof(List_t));

    //set the previous element of the new list element
    if (pParamPrevElem == NULL){
        pList->pPrevElem = pList;
    }
    else {
        pList->pPrevElem = pParamPrevElem;
    }

    //set the next element of the new list element
    pList->pNextElem = pParamNextElem;
    //set the item to the new list element
    pList->pItem = pParamItem;

    return pList;
}

List_t *List_create(void){

    return Element_create(NULL, NULL, NULL);
}

int List_destroy(List_t *pList){

    if (pList->pNextElem != NULL){
        List_destroy(pList->pNextElem);
    }

    free(pList);
}

//returns a pointer to the list element at a certain index 
List_t *List_crawl(List_t *pList, unsigned index){
    int i = 0;
    List_t *pListCrawler = pList;

    //make sure the crawler points to an existing list element
    while(pListCrawler != NULL){
        //if we reached the desired index, return current crawler pointer
        if (i == index){
            return pListCrawler;
        }

        pListCrawler = pListCrawler->pNextElem;
        i++;
    }

    //if we could not reach the desired index, return null pointer
    return NULL;
}

int List_insert(List_t *pList, void *item, unsigned index){
    //crawl in the list until you find desired list element
    List_t *pTarget = List_crawl(pList,index);

    //if target list element is null (crawl failed)
    if (pTarget == NULL){

        //desired list element does not exist
        return 0;
    }

    //if there is only one element in the list (implicitly meaning that we searched for index 0)
    else if (pList->pPrevElem == pList){
        
        //no list element can be added at index 0
        return 0;
    }

    else{
        //create new list element
        List_t *pInsert = Element_create(pTarget->pPrevElem, pTarget, item);

        //get pointer to list element before target list element
        List_t *pPrevTarget = pTarget->pPrevElem;
        //and update its next list element
        pPrevTarget->pNextElem = pInsert;

        //update target previous list element
        pTarget->pPrevElem = pInsert;

        return 1;
    }

}

void* List_remove(List_t *pList, unsigned index){
    //crawl in the list until you find desired list element
    List_t *pTarget = List_crawl(pList,index);

    //if target list element is null (crawl failed)
    if (pTarget == NULL){

        //desired list element does not exist
        return 0;
    }

    //if there is only one element in the list (implicitly meaning that we searched for index 0)
    else if (pList->pPrevElem == pList){
        
        //no list element can be added at index 0
        return 0;
    }

    //if we are at the end of the list
    else if (pTarget->pNextElem == NULL){
        //call the pop function
        List_pop(pList);

        return 1;
    }

    else {
        //get pointer to list element before target list element
        List_t *pPrevTarget = pTarget->pPrevElem;
        //and update its next list element
        pPrevTarget->pNextElem = pTarget->pNextElem;

        //get pointer to list element after target list element
        List_t *pNextTarget = pTarget->pNextElem;
        //and update its next list element
        pNextTarget->pPrevElem = pPrevTarget;

        //delete target list element
        free(pTarget);
    }
}

int List_push(List_t *pList, void *item){
    //retreive pointer to old last list element
    List_t *pOldLast = pList->pPrevElem;
    //create new last list element
    List_t *pNewLast = Element_create(pOldLast, NULL, item);
    //update pointer in old last list element
    pOldLast->pNextElem = pNewLast;
    //update pointer in first list element
    pList->pPrevElem = pNewLast;

    return 1;
}

void* List_pop(List_t *pList){
    //retreive pointer to old last list element
    List_t *pOldLast = pList->pPrevElem;

    //check that we do not pop the list element zero
    if (pOldLast == pList){
        return NULL;
    }

    else {
        //retreive currently penultimate list element (that will become the last list element)
        List_t *pNewLast = pOldLast->pPrevElem;
        //udpate pointers in new last list element
        pNewLast->pNextElem = NULL;
        //update pointers in first list element
        pList->pPrevElem = pNewLast;

        free(pOldLast);
    }
}

int List_getSize(List_t *pList){
    int i = 0;
    List_t *pListCrawler = pList;

    //make sure the crawler points to an existing list element
    while(pListCrawler != NULL){

        pListCrawler = pListCrawler->pNextElem;
        i++;
    }

    //substract one as list element zero does not hold any data
    return i-1;
}

//sorts the list using the bubble sort algoritm
int List_sort(List_t *pList){
    int i, j, switched, size;
    size = List_getSize(pList);

    if (size < 2){
        //list is already sorted (one element only)
        return 0;
    }

    for (i = 0; i < size -1; i++) {

        switched = 0;
        List_t *pListCrawler = pList->pNextElem;

        for (j = 0; j < size - i - 1 ; j++) {

            List_t *pListNextCrawler = pListCrawler->pNextElem;
            if (*(int*)(pListCrawler->pItem) > *(int*)(pListNextCrawler->pItem)){
                List_switch(pList, pListCrawler);
                switched = 1;
            }

            pListCrawler = pListNextCrawler;
        }

        if (switched == 0){
            break;
        }
        
    }

}

//return pointer to item contained at a certain index in the list
void* List_get(List_t *pList, unsigned index){

    //crawl in the list until you find desired list element
    List_t *pTarget = List_crawl(pList,index);

    //if list element is not null (crawl succeeded)
    if (pTarget != NULL){
        //return pointer to list element item
        return pTarget->pItem;
    }
    else{
        return NULL;
    }
}

//displays list elements on the console (all list items are considered to be pointer integers)
int List_display(List_t *pList){
    //check that list element we are about to print is not the first list element
    if (pList->pItem != NULL){
        printf("%d\r\n", *(int*)(pList->pItem));
    }

    //check that next list element is valid
    if (pList->pNextElem != NULL){
        List_display(pList->pNextElem);
    }
}

//swtiches list elements at index and index + 1
int List_switch(List_t *pList, List_t *pIndex){
    List_t *pPrevIndex = pIndex->pPrevElem;
    List_t *pNextIndex = pIndex->pNextElem;
    List_t *pNextNextIndex = pNextIndex->pNextElem;

    //updating pointers in neighbors list elements
    pPrevIndex->pNextElem = pNextIndex;

    //if the next next index is still a valid list element
    if (pNextNextIndex != NULL){
        //update the next next pointers
        pNextNextIndex->pPrevElem = pIndex;
    }
    else{
        //update the pointers of the list element zero  (last element from the list will change !)
        pList->pPrevElem = pIndex;
    }
    
    //updating pointers in index and next index list elements
    pNextIndex->pPrevElem = pPrevIndex;
    pNextIndex->pNextElem = pIndex;
    pIndex->pPrevElem = pNextIndex;
    pIndex->pNextElem = pNextNextIndex;
    
}