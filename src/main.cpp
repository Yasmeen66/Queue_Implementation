#include <iostream>
using namespace std;

#define ARRAY_BASED_QUEUE
#include"queue.cpp"


int main()
{
    Queue q;
    int elem;
    CreateQueue(&q);
    Append(12,&q);
    Append(6,&q);
    Append(7,&q);
    Append(1,&q);
    Append(5,&q);
    Append(3,&q);
    TraverseQueue(&q,&Display);
    int SZ=QueueSize(&q);
    cout<<"Size of queue :- "<<SZ<<endl;
    Serve(&elem,&q);
    Serve(&elem,&q);
    Serve(&elem,&q);
    SZ=QueueSize(&q);
    cout<<"Size of queue :- "<<SZ<<endl;
    TraverseQueue(&q,&Display);
    ClearQueue(&q);
    SZ=QueueSize(&q);
    cout<<"Size of queue :- "<<SZ<<endl;
    return 0;
}


