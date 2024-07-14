// double ended queue
#include<stdio.h>
#define MAX 5
struct queue
{
    int data[MAX];
    int front,rear;
};
void enquefront(struct queue *sp,int x);
void enquerear(struct queue *sp,int x);
int dequefront(struct queue *sp);
int dequerear(struct queue *sp);
void display(struct queue sp);
main()
{
    struct queue sp;
    sp.front=sp.rear=-1;
    enquefront(&sp,20);
    enquerear(&sp,30);
    enquerear(&sp,90);
    enquefront(&sp,60);
    dequefront(&sp);
    dequerear(&sp);
    display(sp);
}
void enquefront(struct queue *sp,int x)
{
    if((sp->front==sp->rear+1)||(sp->front==0 && sp->rear==MAX-1))
    {
        printf("Queue is full\n");
    }
    else if(sp->front==-1 && sp->rear==-1)
    {
        sp->front=sp->rear=0;
        sp->data[sp->front]=x;
    }
    else if(sp->front==0)
    {
        sp->front=MAX-1;
        sp->data[sp->front]=x;
    }
    else
    {
        --(sp->front);
        sp->data[sp->front]=x;
    }
}
void enquerear(struct queue *sp,int x)
{
    if((sp->front==sp->rear+1)||(sp->front==0 && sp->rear==MAX-1))
    {
        printf("Queue is full\n");
    }
    else if(sp->front==-1 && sp->rear==-1)
    {
        sp->front=sp->rear=0;
        sp->data[sp->front]=x;
    }
    else if(sp->rear==MAX-1)
    {
         sp->rear=0;
         sp->data[sp->rear]=x;   
    }
    else
    {
        ++(sp->rear);
        sp->data[sp->rear]=x;
    }
}
int dequefront(struct queue *sp)
{
    int x;
     if((sp->front==-1 && sp->rear==-1) )
     {
        printf("queue is empty\n");
     }
     else if(sp->front==sp->rear)
     {
        x=sp->data[sp->front];
        sp->front=sp->rear=-1;
        return(x);
     }
     else if(sp->front==MAX-1)
     {
        x=sp->data[sp->front];
        sp->front=0;
        return(x);
     }
     else
     {
         x=sp->data[sp->front];
         ++(sp->front);
         return(x);
     }
}
int dequerear(struct queue *sp)
{
    int x;
     if((sp->front==-1 && sp->rear==-1) )
     {
        printf("queue is empty\n");
     }
     else if(sp->front==sp->rear)
     {
        x=sp->data[sp->front];
        sp->front=sp->rear=-1;
        return(x);
     }
     else if(sp->rear==0)
     {
        x=sp->data[sp->rear];
        sp->rear=MAX-1;
        return(x);
     }
     else
    {
          x=sp->data[sp->rear];
          --(sp->rear);
          return(x);
     }

}
void display(struct queue sp)
{
    int i;
    i=sp.front;
    if(i==-1)
    {
        printf("Queue is empty\n");
    }
    while(i!=sp.rear)
    {
        printf("%d\n",sp.data[i]);
        i=(i+1)%MAX;
    }
    printf("%d\n",sp.data[sp.rear]);
}