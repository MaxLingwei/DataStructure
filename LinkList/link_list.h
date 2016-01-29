#ifndef LIST_H
#define LIST_H

#include <stdio.h>

#define EMPTY 0

#define OK 0
#define ERROR -1

#define TRUE 1
#define FALSE 0

/*Define a structure for linklist elements.*/
typedef struct ListElmt_
{
    void *data;
    struct ListElmt_ *next;
}ListElmt;

/*Define a structure for linklist.*/
typedef struct List_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    ListElmt *head;
    ListElmt *tail;
}List;


/*Public Interface*/
int list_init(List *list, void (*destroy)(void *data));
int list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) (list->size)
#define list_head(list) (list->head)
#define list_tail(list) (list->tail)
#define list_is_head(list, element) ((element) == (list)->head ? TRUE : FALSE)
#define list_is_tail(element) ((element)->next == NULL ? TRUE : FALSE)
#define list_data(element) (element->data)
#define list_next(element) (element->next)



#endif
