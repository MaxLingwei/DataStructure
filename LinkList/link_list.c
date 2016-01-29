#include <stdlib.h>
#include <string.h>
#include "link_list.h"


int list_init(List *list, void (*destroy)(void *data))
{
    if (NULL == list)
    {
        return ERROR;
    }
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->destroy = destroy;

    return OK;
}

int list_destroy(List *list)
{
    void *data;
    
    while(list_size(list) > 0)
    {
        if (OK == list_rem_next(list, NULL, (void **)&data) &&
            NULL != list->destroy)
        {
            list->destroy(list);
        }
    }

    memset(list, 0, sizeof(List));
    return OK;
}

int list_ins_next(List *list, ListElmt *element, const void *data)
{
    ListElmt *new_element = NULL;

    new_element = (ListElmt *)malloc(sizeof(ListElmt));
    if (NULL == new_element)
    {
        return ERROR;
    }
    new_element->data = (void *)data;

    if (NULL == element)
    {
        if (EMPTY == list_size(list))
        {
            list->tail = new_element;
        }
        new_element->next = list->head;
        list->head = new_element;
    }
    else
    {
        if (NULL == element->next)
        {
            list->tail = new_element;
        }
        new_element->next = element->next;
        element->next = new_element;
    }

    list->size++;

    return OK;
}

int list_rem_next(List *list, ListElmt *element, void **data)
{
    ListElmt *old_element = NULL;
    if (EMPTY == list_size(list))
    {
        return ERROR;
    }
    if (NULL == element)
    {
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;

        if (1 == list_size(list))
        {
            list->tail = NULL;
        }
    }
    else
    {
        if (NULL == element->next)
        {
            return ERROR;
        }
        old_element = element->next;
        *data = old_element->data;
        element->next = element->next->next;

        if (NULL = element->next)
        {
            list->tail = element;
        }
    }

    free(old_element);
    list->size--;
    return OK;
}
