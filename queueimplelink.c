// queue using link list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enque(int x);
int deque();
void display();
main()
{
    int x;
    enque(10);
    enque(20);
    enque(30);
    enque(40);
    x=deque();
    printf("The dequed element is %d\n",x);
    display();
    printf("New\n");
    deque();
    display();
     
}
void enque(int x)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
       new->data=x;
       new->next=NULL;

    if(front==NULL && rear==NULL)
    {
         front=rear=new;
    }
    else
    {
      rear->next=new;
      rear=new;
    }
}
int deque()
{
    struct node *temp;
    int x;
    if(front==NULL && rear==NULL)
      printf("Empty list\n");
    else
    {
      temp=front;
      x=temp->data;
      front=front->next;
      free(temp);
      return(x);
    }
}
void display()
{
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
      

