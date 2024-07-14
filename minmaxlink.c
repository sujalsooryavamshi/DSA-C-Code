#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void minmax(struct node *s,int *min,int *max);
int main()
{
    struct node *head,*newnode,*temp;
    int choice;
    int *min,*max;
    min=(int *)malloc(sizeof(int));
    max=(int *)malloc(sizeof(int));
    *min=0;
    *max=0;
    head=0;
    while(choice)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
     newnode->next=0;
    if(head==0)
      head=temp=newnode;
    else
      temp->next=newnode;
      temp=newnode;
    
    printf("Enter the choice(0,1)\n");
    scanf("%d",&choice);
    }
    temp=head;
    while(temp!=NULL)
    {
       printf("%d\n",temp->data);
       temp=temp->next;
    }
    minmax(head,min,max);    
}
void minmax(struct node *s,int *min,int *max)
{
    struct node *temp;
    temp=s;
    if(s==NULL)
      printf("List is empty\n");
    else if(s->next==NULL)
      printf("List has only one element\n");
    else 
    {
     *min=temp->data;
     *max=temp->data;
     while(temp!=NULL)
     {
          if(temp->data < *min)
              *min=temp->data;
          if(temp->data > *max)
             *max=temp->data;
          temp=temp->next;
     }
     printf("The min and max element is %d and %d\n",*min,*max);
    }
}