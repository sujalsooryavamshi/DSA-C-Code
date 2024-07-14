#include<stdio.h>
//revrse is also done here and implementation
#define MAX 4
struct queue
{
    int front,rear;
    int data[MAX];
};
void enque(struct queue *sp,int x);
int deque(struct queue *sp);
void display (struct queue sp);
int isfull(struct queue *sp);
int isempty(struct queue *sp);
void rev(struct queue *sp);
main()
{
    int x,y;
    struct queue sp;
    sp.front=-1;
    sp.rear=-1;
    enque(&sp,20);
    enque(&sp,30);
    enque(&sp,40);
    display(sp);
    rev(&sp);
    display(sp);
}
void enque(struct queue *sp,int x)
{
    if(isfull(sp))
      printf("Queue is full\n");
    else if(sp->front==-1 && sp->rear==-1)
    {
         sp->front=sp->rear=0;
         sp->data[sp->rear]=x;
    }
    else{
      ++sp->rear;
      sp->data[sp->rear]=x;
    }
}
int deque(struct queue *sp)
{
    int x;
    if(isempty(sp))
      printf("Queue is empty\n");
    else if(sp->front==sp->rear)
    {
        x=sp->data[sp->front];
          sp->front=sp->rear=-1;
        return(x);
    }
    else 
      {
          x=sp->data[sp->front];
          sp->front++;
          return(x);
      }
}
void display (struct queue sp)
{
    int i;
    for(i=sp.front;i<=sp.rear && i>=0;++i)
       printf("%d\n",sp.data[i]);

}
int isfull(struct queue *sp)
{
    if(sp->rear==MAX-1)
       return(1);
    else
      return(0);
}
int isempty(struct queue *sp)
{
    if(sp->rear==-1 && sp->front==-1)
      return(1);
    else
      return(0);    
}
void rev(struct queue *sp)
{
  int x;
   if(!isempty(sp))
    {
       x=deque(sp);
       rev(sp);
       enque(sp,x); 
    }
}
