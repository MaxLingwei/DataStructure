#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int InitQueue(Queue *pstQueue)
{
    if (NULL == pstQueue)
    {
        return ERROR;
    }
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
    if (NULL == pstQueue)
    {
        return ERROR;
    }
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
    QueuePtr pstQueuePrt = NULL;
    
    if (NULL == pstQueue)
    {
        return ERROR;
    }
    else if (0 == pstQueue->iQueueSize)
    {
        return OK;
    }

    pstQueue->pstRear = pstQueue->pstFront->pstNext;

    while (NULL == pstQueue->pstRear)
    {
        pstQueuePrt = pstQueue->pstRear->pstNext;
        free(pstQueue->pstRear);
        pstQueue->pstRear = pstQueuePrt;
    }
    pstQueue->pstRear = pstQueue->pstFront;
    pstQueue->iQueueSize = 0;
    pstQueue->pstFront->pstNext = NULL;

    return OK;
}
int IsQueueEmpty(Queue *pstQueue)
{
    if (NULL == pstQueue)
    {
        return ERROR;
    }

    if (0 == pstQueue->iQueueSize)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int GetQueueLength(Queue *pstQueue)
{
    if (NULL == pstQueue)
    {
        return ERROR;
    }
    return pstQueue->iQueueSize;
}

int GetQueueHead(Queue *pstQueue, Data *pstData)
{
    if (0 == pstQueue->iQueueSize)
    {
        return ERROR;
    }
    memcpy(pstData, &(pstQueue->pstFront->pstNext->stData), sizeof(Data));
    return OK;
}

int EnQueue(Queue *pstQueue, Data *pstData)
{
    QueuePtr pstNewNode = NULL;
    if (NULL == pstQueue)
    {
        return ERROR;
    }

    pstNewNode = (QueuePtr)malloc(sizeof(QueueNode));
    memset(pstNewNode, 0, sizeof(QueueNode));
    memcpy(pstNewNode->stData, pstData, sizeof(Data));
    pstQueue->pstRear->pstNext = pstNewNode;
    pstQueue->pstRear = pstNewNode;
    pstQueue->iQueueSize++;
    return OK;
}

int DeQueue(Queue *pstQueue, Data *pstData)
{
    QueuePtr pstTemp = NULL;

    if (NULL == pstQueue || 0 == pstQueue->iQueueSize)
    {
        return ERROR;
    }
    pstTemp = pstQueue->pstFront->pstNext;
    pstQueue->pstFront = pstTemp->pstNext;
    pstQueue->iQueueSize--;
    free(pstTemp);
    pstTemp = NULL;

    return OK;
}
