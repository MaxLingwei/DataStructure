#define IN
#define OUT

#define OK 0
#define ERROR -1




typedef struct tagData
{
    int iData;
}Data;

struct tagStackNode
{
    Data stData;
    struct tagStackNode *pstNext;
};
typedef struct tagStackNode *StackNode;
struct tagStack
{
    StackNode pstTop;
    StackNode pstBase;
    int iStackSize;
};
typedef tagStack *Stack;

int InitStack(IN Stack pstStack);
int DestroyStack(IN Stack pstStack);
int ClearStack(IN Stack pstStack);
int IsEmptyStack(IN Stack pstStack);
int PopStack(IN Stack pstStack, Data *pstData);
int PushStack(IN Stack pstStack, Data *pstData);
int GetLengthOfStack(IN Stack pstStack, OUT int *piLength);
int GetTopOfStack(IN Stack pstStack, Data *pstData);
