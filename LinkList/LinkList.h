#define IN
#define OUT 

#define OK 0
#define ERROR -1

#define FALSE 0
#define TRUE 1

typedef struct tagData
{
    int iData;
}Data;

struct tagLinkListNode
{
    struct tagLinkListNode *pstNext;
    Data stData;
};

typedef struct tagLinkListNode *LinkListNode;

typedef struct tagLinkList
{
    LinkListNode pstHead;
    LinkListNode pstTail;
    int iListLen;
}LinkList;

LinkListNode _linklist_MakeNode();

int _linklist_FreeNode();


int LinkList_InitList(IN LinkList *pstLinkList);

int LinkList_ClearList(IN LinkList *pstLinkList);

int LinkList_InsertNodeBefore(IN LinkList *pstLinkList,
                              IN LinkListNode pstLinkListNode,
                              IN Data *pstData);

int LinkList_DeleteNode(IN LinkList *pstLinkList,
                        IN LinkListNode pstLinkListNode);

int LinkList_SetNodeData(IN LinkList *pstLinkList, IN Data *pstData);

int LinkList_GetNodeData();

int LinkList_GetListLength(IN LinkList *pstLinkList, OUT int *piLength);

int LinkList_IsListEmpty();

int LinkList_LocateNodePosition(IN LinkList *pstLinkList,
                                IN int iPosition, 
                                OUT LinkListNode *pstLinkListNode);
