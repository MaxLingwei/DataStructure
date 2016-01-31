#include <stdlib.h>
#include <string.h>

#include "clist.h"

int clist_init(CList *list, void (*destroy)(void *data))
{
    if (NULL == list)
    {
        return ERROR;
    }

    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    
    return OK;
}

int clist_destroy(CList *list)
{
    void *data = NULL;

    while (clist_size(list) > EMPTY)
    {
        if (OK == clist_rem_next(list, list->head, (void **)&data) &&
            NULL != list->destroy)
        {
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(Clist));
    return OK;
}

int clist_ins_next(CList *list, CListElmt *element, const void *data)
{
    CListElmt *new_element =NULL;

    new_element = (CListElmt *)malloc(sizeof(CListElmt));
    if (NULL == new_element)
    {
        return ERROR;
    }

    new_element->data = (void *)data;
    if (EMPTY == list->size)
    {
        list->head = new_element;
        new_element->next = new_element;
    }
    else
    {
        new_element->next = element->next;
        element->next = new_element->next;
    }
    list->size++;
    return OK;
}

int clist_rem_next(CList *list, CListElmt *element, void **data)
{
    CListElmt *old_element = NULL;

    if (EMPTY == clist_size(list))
    {
        return ERROR;
    }

    *data = element->next;

    if (element->next == element)
    {
        old_element = element;
        list->head = NULL;
    }
    else
    {
        old_element = element->next;
        element->next = element->next->next;

        if (old_element == list_head(list))
        {
            list->head = old_element->next;
        }
    }

    free(old_element);
    list->size--;
    return OK;
}
