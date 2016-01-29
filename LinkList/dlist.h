#ifndef DLIST_H
#define DLIST_H


#include <stdio.h>

typedef struct DListElmt_
{
    void *data;
    struct DListElmt_ *prev;
    struct DListElmt_ *next;
}DListElmt;

typedef struct Dlist_
{
    int size;
    int (*match)(const void *key1, const void key2);
    void (*destroy)(void *data);
    DListElmt *head;
    DListElmt *tail;
}Dlist;


/*Public interface*/
void dlist_init(Dlist *list, void (*destroy)(void *data));
void dlist_destroy(Dlist *list);
int dlist_ins_next(Dlist *list, DListElmt *element, const void *data);
int dlist_ins_prev(Dlist *list, DListElmt *element, const void *data);
int dlist_remove(Dlist *list, DListElmt *element, void **data);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tais(list) ((list)->tail)
#define dlist_is_head(list) ((element)->prev == NULL ? TRUE : FALSE)
#define dlist_is_tail(list) ((element)->next == NULL ? TRUE : FALSE)
#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)


#endif
