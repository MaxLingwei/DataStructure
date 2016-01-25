#include<stdio.h>

#include"Stack.h"

int InitStack(IN Stack pstStack)
{
    if (NULL == pstStack)
    {
        return ERROR;
    }
    pstStack->pstTop = NULL;
    pstStack->pstBase = NULL;
    pstStack->iStackSize = 0;
    
    return OK;
}

int DestroyStack()
{}

int ClearStack()
{}

int IsEmptyStack()
{}

int PopStack()
{}

int PushStack()
{}

int GetLengthOfStack()
{}

int GetTopOfStack()
{}

