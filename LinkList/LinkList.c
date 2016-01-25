#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

#include"LinkList.h"

int LinkList_InitList(IN LinkList *pstLinkList)
{
    pstLinkList->pstHead = NULL;
    pstLinkList->pstTail = NULL;
    pstLinkList->iListLen = 0;

    return OK;
}

int LinkList_ClearList(IN LinkList *pstLinkList)
{
    LinkListNode pstListNode;
    LinkListNode pstListNodeNext;
    pstListNode = NULL;
    pstListNodeNext = NULL;
    
    pstListNode = pstLinkList->pstHead;
    while (pstLinkList->pstTail != pstListNode)
    {
        pstListNodeNext = pstListNode->pstNext;
        free(pstListNode);
        pstListNode =  pstListNodeNext;
    }
    free(pstLinkList->pstTail); 

    pstLinkList->pstHead = NULL;
    pstLinkList->pstTail = NULL;
    pstLinkList->iListLen = 0;

    return OK;
}

int LinkList_InsertNodeBefore(IN LinkList *pstLinkList,
                              IN LinkListNode pstLinkListNode, 
                              IN Data *pstData)
{
    LinkListNode pstNext = NULL;
    LinkListNode pstNodeTemp = NULL;

    if (NULL == pstLinkList->pstHead)
    {
        return ERROR;
    }
    pstNext = pstLinkList->pstHead;

    while (pstLinkListNode != pstNext->pstNext)
    {
        pstNext = pstNext->pstNext;
    }
    pstNodeTemp = (LinkListNode)malloc(sizeof(struct tagLinkListNode));

    memcpy(&(pstNodeTemp->stData), pstData, sizeof(Data));
    pstNodeTemp->pstNext = pstNext->pstNext;
    pstNext->pstNext = pstNodeTemp;
    return OK;
}

int LinkList_IsListEmpty(LinkList *pstLinkList)
{
    int iRet = FALSE;

    if (pstLinkList->pstTail == pstLinkList->pstHead)
    {
        iRet = TRUE;
    }
    else 
    {
        iRet = FALSE;
    }

    return iRet;
}

int LinkList_LocateNodePosition(IN LinkList *pstLinkList,
                                IN int iPosition,
                                OUT LinkListNode *ppstLinkListNode)
{
    int i;
    LinkListNode pstNode = NULL;
    LinkListNode pstNext = NULL;

    if (pstLinkList->iListLen < iPosition)
    {
        (*ppstLinkListNode) = NULL;
        return ERROR;
    }

    pstNode = pstLinkList->pstHead;
    for (i = 0; i < iPosition; i++)
    {
        pstNode = pstNode->pstNext;    
    }

    (*ppstLinkListNode) = pstNode;
    return OK;
}

int LinkList_DeleteNode(IN LinkList *pstLinkList,
                        IN LinkListNode pstLinkListNode)
{
    LinkListNode pstNext = NULL;
    LinkListNode pstTemp = NULL;
    pstNext = pstLinkList->pstHead;

    while(pstNext->pstNext != pstLinkListNode)
    {
        pstNext = pstNext->pstNext;
    }
    pstTemp = pstNext->pstNext;
    pstNext->pstNext = pstTemp->pstNext;
    free(pstTemp);

    return OK;
}

int LinkList_SetNodeData(IN LinkList *pstLinkList, IN Data *pstData)
{
}
int LinkList_GetListLength(IN LinkList *pstLinkList, OUT int *piLength)
{
    int iLength = 0;
    LinkListNode pstListNode = NULL;

    pstListNode = pstLinkList->pstHead;
    while (pstListNode != NULL)
    {
        pstListNode = pstListNode->pstNext;
        iLength++;
    }
    *piLength = iLength;
    return OK;
}
