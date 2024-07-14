// circular queue
#include<stdio.h>
#define max 6
struct que
{
    int data[max];
    int front,rear;
};
void enque(struct que *s,int x);
int deque(struct que *s);
void display(struct que s);
main()
{
    int x;
    struct que s;
    s.front=s.rear=-1;
    enque(&s,20);
    enque(&s,30);
    enque(&s,40);
    enque(&s,50);
    enque(&s,60);
    x=deque(&s);
    printf("The dequed element is %d\n",x);
    enque(&s,70);
    enque(&s,80);
    enque(&s,90);
    display(s);
    
}
void enque(struct que *s,int x)
{
    if(s->front==-1 && s->rear==-1)
    {
        s->front=s->rear=0;
        s->data[s->rear]=x;
    }
    else if(((s->rear+1)%max)==s->front)
    {
        printf("Que is full\n");
    }
    else
    {
      s->rear=(s->rear+1)%max;
      s->data[s->rear]=x;
    }
}
int deque(struct que *s)
{
    int x;
    if(s->front==-1 && s->rear==-1)
      printf("Que is empty\n");
    else if(s->front==s->rear)
      {
        x=s->data[s->front];
          s->front=s->rear=-1;
          return(x);
      }
    else
    {
        x=s->data[s->front];
        s->front=(s->front+1)%max;
        return(x);
    }
}
void display(struct que s)
{
    int i;
    for( ;s.front!=s.rear;s.front=(s.front+1)%max)
    {
        printf("%d\n",s.data[s.front]);
    }
    printf("%d",s.data[s.rear]);
}