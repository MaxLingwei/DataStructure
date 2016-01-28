#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int InitQueue(Queue *pstQueue)
{
    pstQueue->pstFront = (QueuePtr)malloc(sizeof(QueueNode));

    if (NULL == pstQueue->pstFront)
    {
        return ERROR;
    }
    else
    {
        pstQueue->pstRear = pstQueue->pstFront;
        pstQueue->iQueueSize = 0;
        pstQueue->pstFront->pstNext = NULL;
    }
    return OK;
}

int DestroyQueue(Queue *pstQueue)
{
    while (NULL != pstQueue->pstFront)
    {
        pstQueue->pstRear = pstQueue->pstFront->pstNext;
        free(pstQueue->pstFront);
        pstQueue->pstRear = pstQueue->pstFront;
    }
    return OK;
}

int ClearQueue(Queue *pstQueue)
{

}
