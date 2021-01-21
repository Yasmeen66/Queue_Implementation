#ifdef ARRAY_BASED_QUEUE
#include"../include/queue.h"


void CreateQueue(Queue *pq)
{
    pq->Front=0;
    pq->Rear=-1;
    pq->Size=0;
}
void Append(int elem,Queue *pq)
{
    if(QueueFull(pq))
        cout<<"Queue is Full ! "<<endl;
    else
    {
        if(pq->Rear==MaxQueue-1)
            pq->Rear=0;
        else
            pq->Rear++;
        pq->entry[pq->Rear]=elem;
        pq->Size++;
    }
}
void Serve(int *pe,Queue *pq)
{
    if(QueueEmpty(pq))
        cout<<"Queue is Empty ! "<<endl;
    else
    {
        *pe=pq->entry[pq->Front];
        if(pq->Front==MaxQueue-1)
            pq->Front=0;
        else
            pq->Front++;
        pq->Size--;
    }
}
int QueueEmpty(Queue *pq)
{
    return !pq->Size;
}
int QueueFull(Queue *pq)
{
    return (pq->Size==MaxQueue);
}
int QueueSize(Queue *pq)
{
    return pq->Size;
}
void ClearQueue(Queue *pq)
{
    pq->Front=0;
    pq->Rear=-1;
    pq->Size=0;
}
void TraverseQueue(Queue *pq,void(*pf)(int))
{
    int pos,x=1;
    for(pos=pq->Front; x<=pq->Size; x++)
    {
        (*pf)(pq->entry[pos]);
        pos=(pos+1)%MaxQueue;
    }
    cout<<endl;
}
void Display(int elem)
{
    cout<<elem<<" ";
}


#else
#include"../include/queue.h"


void CreateQueue(Queue *pq)
{
    pq->Front=NULL;
    pq->Rear=NULL;
    pq->Size=0;
}
void Append(int elem,Queue *pq)
{
    QueueNode pn=(QueueNode *)malloc(sizeof(QueueNode));
    if(!pn)
        cout<<"There is no enough memory to add any data !"<<endl;
    else
    {
        pn->next=NULL;
        pn->ele=elem;
        if(!pq->Rear)
            pq->Front=pn;
        else
            pq->Rear->next=pn;
        pq->Rear=pn;
        pq->Size++;
    }
}
void Serve(int *pe,Queue *pq)
{
    QueueNode *pn=pq->Front;
    *pe=pn->ele;
    pq->Front=pn->next;
    free(pn);
    if(!pq->Front)
        pq->Rear=NULL;
    pq->Size--;
}
int QueueEmpty(Queue *pq)
{
    return !pq->Size;
}
int QueueFull(Queue *pq)
{
    return 0;
}
int QueueSize(Queue *pq)
{
    return pq->Size;
}
void ClearQueue(Queue *pq)
{
    while(pq->Front)
    {
        pq->Rear=pq->Front->next;
        free(pq->Front);
        pq->Front=pq->Rear;
    }
    pq->Size=0;
}
void TraverseQueue(Queue *pq,void(*pf)(int))
{
    for(QueueNode *pn=pq->Front; pn; pn=pn->next)
        (*pf)(pn->ele);
    cout<<endl;
}
void Display(int elem)
{
    cout<<elem<<" ";
}
#endif
