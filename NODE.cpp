#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *pNext;
    
} Node,*pNode;

void create_list(pNode phead,int value)
{
    pNode p = phead;
    while (p->pNext!=NULL)
    {
        p = p->pNext;
    }
    pNode pnew = new Node;
    pnew->pNext = NULL;
    p->pNext = pnew;
    pnew->data = value;
}

void show_list(pNode phead)
{
    pNode p = phead->pNext;
    while (p!=NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl;
}

int search(pNode phead,int value)
{
    pNode p = phead->pNext;
    int i = 0;
    while (p!=NULL)
    {
        if (p->data==value)
        {
            return i;
        }
        else
        {
            i++;
            p = p->pNext;
        }
    }
    return -1;
    if (p->pNext)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

bool Is_empty(pNode phead)
{
    if (phead->pNext == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void delete_node(pNode phead,int poi)
{
    pNode p = phead;
    if (Is_empty(phead))
    {
        cout << "删除失败，因为链表为空" << endl;
        return;
    }
    else
    {
        for (int i = 0;i<poi;i++)
        {
            p = p->pNext;
        }
        pNode r = p->pNext;
        p->pNext = p->pNext->pNext;
        r->pNext = NULL;
        delete r;
    }
    
}

void insert_list(pNode phead,int poi,int value)
{
    if (Is_empty(phead))
    {
        cout << "插入失败,因为链表为空！" << endl;
        return;
    }
    else
    {
        pNode p = phead;
        for (int i = 0;i<poi;i++)
        {
            p = p->pNext;
        }
        pNode pnew = new Node;
        pnew->pNext = NULL;
        pNode r = p->pNext;
        p->pNext = pnew;
        pnew->pNext = r;
        pnew ->data = value;
    }
}

int length(pNode phead)
{
    pNode p = phead;
    int i = 0;
    while (p->pNext!=NULL)
    {
        i++;
        p = p->pNext;
    }
    return i;
}

void pop_list(pNode phead)
{
    pNode p = phead;
    if (p->pNext==NULL)
    {
        cout << "链表为空，弹出失败"<<endl;
        return;
    }
    while (p->pNext->pNext!=NULL)
    {
        p = p->pNext;
    }
    pNode r = p->pNext;
    p->pNext = NULL;
    delete r;
}
void clear_list(pNode phead)
{
    pNode p = phead->pNext;
    pNode r = p->pNext;
    while (p!=NULL)
    {
        r=p->pNext;
        delete p;
        p = r;
    }
    phead->pNext =NULL;
}
int main()
{
    pNode phead = new Node;
    phead->pNext = NULL;
    create_list(phead,2);
    create_list(phead,3);
    create_list(phead,5);
    create_list(phead,8);
    create_list(phead,7);
    show_list(phead);
    cout << "链表的长度为:" << length(phead) << endl;
    int poi = search(phead,8);
    cout <<"数字8的位置是："<< poi <<endl;
    if (Is_empty(phead))
    {
        cout << "链表为空" << endl;
    }
    else
    {
        cout << "链表不为空" << endl;
    }
    delete_node(phead,2);
    show_list(phead);
    cout << "链表的长度为:" << length(phead) << endl;
    insert_list(phead,2,8);
    show_list(phead);
    cout << "链表的长度为:" << length(phead) << endl;
    pop_list(phead);
    show_list(phead);
    cout << "链表的长度为:" << length(phead) << endl;
    clear_list(phead);
    show_list(phead);
    cout << "链表的长度为:" << length(phead) << endl;
    create_list(phead,8);
    create_list(phead,7);
    show_list(phead);
    cout << "链表的长度为:" << length(phead) << endl;

}