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
int DestroyStack();
int ClearStack();
int IsEmptyStack();
int PopStack();
int PushStack();
int GetLengthOfStack();
int GetTopOfStack();
