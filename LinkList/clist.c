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
}
