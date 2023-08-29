#ifndef LIST_H
#define LIST_H

//we followed this approach for creating a struct that would act like a C++ class : https://stackoverflow.com/a/1403926
struct List_t
{
    //data members declaration
    void* pPrevElem;
    void* pNextElem;
    void* pItem;
};

//use a type def so that we can use List_t iso struct List_t throughout the rest of the program.
typedef struct List_t List_t;

//function members (prototypes) declaration (from assignment)
List_t *List_create(void);
int List_destroy(List_t *pList);
int List_insert(List_t *pList, void *item, unsigned index);
void* List_remove(List_t *pList, unsigned index);
void* List_get(List_t *pList, unsigned index);
int List_push(List_t *pList, void *item);
void* List_pop(List_t *pList);
int List_getSize(List_t *pList);
int List_sort(List_t *pList);


//function members (prototypes) declaration (other)
List_t *Element_create(void* pParamPrevElem,void* pParamNextElem, void* pParamItem);
List_t *List_crawl(List_t *pList, unsigned index);
int List_display(List_t *pList);
int List_switch(List_t *pList, unsigned index);

#endif