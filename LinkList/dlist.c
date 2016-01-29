#include <stdlib.h>
#include <string.h>

#include "dlist.h"


int dlist_init(Dlist *list, void (*destroy)(void *data))
{
    if (NULL == list)
    {
        return ERROR;
    }
    list->size = 0;
    list->destroy = destroy;
    list->head;
    list->tail;
    return OK;
}

int dlist_destroy(Dlist *list)
{
    void *data = NULL;

    while (EMPTY != dlist_size(list))
    {
        if (OK == dlist_remove(list, dlist_tais(list), (void **)&data) && 
            NULL != list->destroy)
        {
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(list));
    return OK;
}

int dlist_ins_next(Dlist *list, DListElmt *element, const void *data)
{
    DListElmt *new_element = NULL;

    if (NULL == element && EMPTY != dlist_size(list))
    {
        return ERROR;
    }
    new_element = (DListElmt *)malloc(sizeof(DListElmt));
    if (NULL == new_element)
    {
        return ERROR;
    }

    new_element->data = (void *)data;

    if (EMPTY == dlist_size(list))
    {
        new_element->prev = NULL;
        new_element->next = NULL;
        list->head = new_element;
        list->tail = new_element;
    }
    else
    {
        new_element->next = element->next;
        new_element->prev = element;

        if (NULL == element->next)
        {
            list->tail = new_element;
        }
        else
        {
            element->next->prev = new_element;
        }
        element->next = new_element;
    }
    list->size++;
    return OK;
}

int dlist_ins_prev(Dlist *list, DListElmt *element, const void *data)
{
    DListElmt *new_element;

    if (NULL == element && EMPTY != dlist_size(list))
    {
        return ERROR;
    }
    new_element = (DListElmt *)malloc(sizeof(DListElmt));
    if (NULL == new_element)
    {
        return ERROR;
    }

    new_element->data = (void *)data;
    if (EMPTY == dlist_size(list))
    {
        new_element->prev = NULL;
        new_element->next = NULL;
        list->head = new_element;
        list->tail = new_element;
    }
    else
    {
        new_element->prev = element->prev;
        new_element->next = element;

        if (NULL == element->prev)
        {
            list->head = new_element;
        }
        else
        {
            element->prev->next = new_element;
        }
        element->prev = new_element;
    }
    list->size++;
    return OK;
}

int dlist_remove(Dlist *list, DListElmt *element, void **data)
{
    if (NULL == element || EMPTY == dlist_size(list))
    {
        return ERROR;
    }
    *data = element->data;
    
    if (element == list->head)
    {
        list->head = element->next;
        
        if (NULL == list->head)
        {
            list->tail = NULL;
        }
        else
        {
            element->next->prev = NULL;
        }
    }
    else
    {
        element->prev->next = element->next;

        if (NULL == element->next)
        {
            list->tail = element->prev;
        }
        else
        {
            element->next->prev = element->prev;
        }
    }
    free(element);
    list->size--;
    return OK;
}
