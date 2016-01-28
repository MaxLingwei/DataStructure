#define OK 0
#define ERROR -1

#define IN
#define OUT
#define TRUE 1
#define FALSE 0


typedef struct tagData
{
    int iData;
}Data;


struct tagQueueNode
{
    Data stData;
    struct tagQueueNode *pstNext;
};

typedef struct tagQueueNode QueueNode;
typedef struct tagQueueNode *QueuePtr;

typedef struct tagQueue
{
    QueuePtr pstFront;
    QueuePtr pstRear;
    int iQueueSize;
}Queue;

int InitQueue(Queue *pstQueue);

int DestroyQueue(Queue *pstQueue);

int ClearQueue(Queue *pstQueue);

int IsQueueEmpty(Queue *pstQueue);

int GetQueueLength(Queue *pstQueue);

int GetQueueHead(Queue *pstQueue, Data *pstData);

int EnQueue(Queue *pstQueue, Data *pstData);

int DeQueue(Queue *pstQueue, Data *pstData);

int QueueTraverse(Queue *pstQueue, (void *)func());


