#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* pNext;
} NODE, * PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pButtom;
} STACK, * PSTACK;
void Init_Stack(PSTACK& pstack)
{

    pstack->pButtom = new NODE;
    pstack->pTop = pstack->pButtom;
    pstack->pButtom->pNext = NULL;
    cout << "进行一个栈的初始化" << endl;
}
void Push_Stack(PSTACK pstack, int value)
{
    PNODE pnew = new NODE;
    pnew->data = value;
    pnew->pNext = pstack->pTop;
    pstack->pTop = pnew;
    cout << "压入：" << pnew->data << endl;
}
void Pop_Stack(PSTACK pstack)
{
    if (pstack->pTop != pstack->pButtom)
    {
        PNODE p = pstack->pTop;
        pstack->pTop = pstack->pTop->pNext;
        cout << "弹出：" << p->data << endl;
        delete p;
    }
    else
    {
        cout << "栈为空，弹出失败" << endl;
        return;
    }


}

bool Is_Empty(PSTACK pstack)
{
    if (pstack->pButtom == pstack->pTop)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Show_Stack(PSTACK pstack)
{
    PNODE p = pstack->pTop;
    if (Is_Empty(pstack))
    {
        cout << "栈为空" << endl;
        return;
    }
    cout << "遍历栈：";
    while (p != pstack->pButtom)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl;
}
void Clear_Stack(PSTACK pstack)
{
    while (pstack->pButtom != pstack->pTop)
    {
        PNODE p = pstack->pTop;
        pstack->pTop = pstack->pTop->pNext;
        delete p;
    }
    cout << "清空栈" << endl;
}
int Length_Stack(PSTACK pstack)
{
    PNODE p = pstack->pTop;
    int len = 0;
    while (p != pstack->pButtom)
    {
        len++;
        p = p->pNext;
    }
    return len;
}
int main()
{
    PSTACK pstack = new STACK;
    Init_Stack(pstack);
    Push_Stack(pstack, 1);
    Show_Stack(pstack);
    Push_Stack(pstack, 2);
    Show_Stack(pstack);
    Push_Stack(pstack, 3);
    Show_Stack(pstack);
    Push_Stack(pstack, 4);
    Show_Stack(pstack);
    Push_Stack(pstack, 5);
    Show_Stack(pstack);

    Pop_Stack(pstack);
    Show_Stack(pstack);
    Pop_Stack(pstack);
    Show_Stack(pstack);

    Clear_Stack(pstack);
    Show_Stack(pstack);

    Push_Stack(pstack, 3);
    Show_Stack(pstack);
    Push_Stack(pstack, 4);
    Show_Stack(pstack);
    Push_Stack(pstack, 5);
    Show_Stack(pstack);
    cout << "栈的长度为：" << Length_Stack(pstack) << endl;
    return 0;
}