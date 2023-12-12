#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node * pNext;
} NODE ,*PNODE;
typedef struct Queue
{
    PNODE rear;
    PNODE front;
} QUEUE,*PQUEUE;

void Init_Queue(PQUEUE &pque)
{
    pque = new QUEUE;
    pque->front = new NODE;
    pque->rear = pque->front;
    pque->rear->pNext = NULL;
    cout << "���г�ʼ���ɹ���"<<endl;
}
void Enter_Queue(PQUEUE pque , int value)
{
    
    PNODE pnew = new NODE;
    pnew->data = value;
    pnew->pNext = NULL;
    pque->rear->pNext = pnew;   //SEGMENT DEFULT
    pque->rear = pnew;
    cout << "��ӳɹ���ֵΪ��"<< pnew ->data << endl;
}
bool Is_Empty(PQUEUE pque)
{
    return pque->front==pque->rear;
}
void Exit_Queue(PQUEUE pque)
{
    PNODE r = pque->front;
    if (!Is_Empty(pque))
    {
        pque->front = pque->front->pNext;
        cout << "���ӳɹ���ֵΪ��"<< r->pNext->data <<endl;
        delete r;
        
    }
    else
    {
        cout << "����Ϊ�գ�����ʧ�ܣ�"<<endl;
        return;
    }
}
void Show_Queue(PQUEUE pque)
{
    PNODE p = pque->front;
    if (Is_Empty(pque))
    {
        cout << "����Ϊ��" <<endl;
        return;
    }
    cout << "��ӡ���У�";
    while(p!=pque->rear)
    {
        cout << p->pNext->data << " ";
        p = p->pNext;
    }
    cout << endl;
}
int Length_Queue(PQUEUE pque)
{
    PNODE p = pque->front;
    int len = 0;
    while (p != pque->rear)
    {
        len++;
        p = p ->pNext;
    }
    return len;
}
void Clear_Queue(PQUEUE pque)
{
    
    while (!Is_Empty(pque))
    {
        PNODE r = pque->front;
        pque->front = pque->front->pNext;
        cout << "���ӳɹ���ֵΪ��"<< r->pNext->data <<endl;
        delete r;
    }
    cout << "������գ�"<<endl;
}
int main()
{
    PQUEUE pque = NULL;
    Init_Queue(pque);
    Enter_Queue(pque,1);
    Enter_Queue(pque,2);
    Enter_Queue(pque,3);
    Enter_Queue(pque,4);
    Enter_Queue(pque,5);
    Show_Queue(pque);
    Exit_Queue(pque);
    Show_Queue(pque);
    Exit_Queue(pque);
    Show_Queue(pque);
    cout << "���еĳ����ǣ�" <<Length_Queue(pque) << endl;
    Clear_Queue(pque);
    Show_Queue(pque);
    cout << "���еĳ����ǣ�" <<Length_Queue(pque) << endl;
    Enter_Queue(pque,4);
    Enter_Queue(pque,5);
    Show_Queue(pque);
    cout << "���еĳ����ǣ�" <<Length_Queue(pque) << endl;
    return 0;
}