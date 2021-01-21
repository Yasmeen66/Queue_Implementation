#ifdef ARRAY_BASED_QUEUE

const int MaxQueue=8;
struct Queue
{
    int Front;
    int Rear;
    int Size;
    int entry[MaxQueue];
};
void CreateQueue(Queue *);

void Append(int,Queue *);

void Serve(int *,Queue *);

int QueueEmpty(Queue *);

int QueueFull(Queue *);

int QueueSize(Queue *);

void ClearQueue(Queue *);

void TraverseQueue(Queue *,void(*pf)(int));

void Display(int );


#else

struct QueueNode
{
    int ele;
    QueueNode *next;
};
struct Queue
{
    QueueNode *Front;
    QueueNode *Rear;
    int Size;
};
void CreateQueue(Queue *);

void Append(int,Queue *);

void Serve(int *,Queue *);

int QueueEmpty(Queue *);

int QueueFull(Queue *);

int QueueSize(Queue *);

void ClearQueue(Queue *);

void TraverseQueue(Queue *,void(*pf)(int));

void Display(int );
#endif

