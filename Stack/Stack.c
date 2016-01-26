#include<stdio.h>

#include"Stack.h"

int InitStack(IN Stack pstStack)
{
    if (NULL == pstStack)
    {
        return ERROR;
    }
    pstStack->pstTop = (StackNode)malloc(sizeof(struct tagStackNode));
    if (pstStack->pstTop != NULL)
    {
        pstStack->pstTop->pstNext = NULL;
        pstStack->pstBase = pstStack->pstTop;
        pstStack->iStackSize = 0;
    }
    else
    {
        return ERROR;
    }
    
    return OK;
}

int DestroyStack(IN Stack pstStack)
{
    ClearStack(pstStack);
    free(pstStack->pstTop);
    pstStack->pstTop = NULL;
    pstStack->pstBase = NULL;
    return OK;
}

int ClearStack(IN Stack pstStack)
{
    StackNode pstTemp = NULL;
    while (pstStack->pstTop != pstStack->pstBase)
    {
        pstTemp = pstStack->pstTop->pstNext;
        free(pstStack->pstTop); 
        pstStack->pstTop = pstTemp;
    }
    pstStack->iStackSize = 0;
    return OK
}


int IsEmptyStack(IN Stack pstStack)
{
    if (pstStack->pstTop == pstStack->pstBase)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int PopStack(IN Stack pstStack, Data *pstData)
{
    StackNode pstNode = NULL;
    pstNode = pstStack->pstTop;
    pstStack->pstTop = pstNode->pstNext;
    memcpy(pstData, pstNode->Data, sizeof(Data));
    free(pstNode);
    return OK;
}

int PushStack(IN Stack pstStack, Data *pstData)
{
    StackNode pstNewNode = NULL;
    pstNewNode = (StackNode)malloc(sizeof(struct tagStackNode));
    pstNewNode->pstNext = pstStack->pstTop;
    pstStack->pstTop = pstNewNode;
    pstStack->iStackSize++;
    return OK;
}

int GetLengthOfStack(IN Stack pstStack, OUT int *piLength)
{
    *piLength = pstStack->iStackSize;
}

int GetTopOfStack(IN Stack pstStack, Data *pstData)
{
    memcpy(pstData, &(pstStack->pstTop->Data), sizeof(Data));
    return OK;
}

