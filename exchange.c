#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node*exchangeheadlast(struct node *s);
main()
{
    struct node *head,*newnode,*temp;
    int choice;
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
   head= exchangeheadlast(head);
   temp=head;
   printf("After alteration the exchange element is head\n");
   while(temp!=NULL)
   {
      printf("%d\n",temp->data);
      temp=temp->next;
   }         
}
struct node*exchangeheadlast(struct node *s)
{
    
    struct node *last,*prev,*temp;
    temp=last=s;
    while(last->next!=NULL)
    {
        prev=last;
        last=last->next;
    }
    last->next=temp->next;
    prev->next=temp;
    temp->next=NULL;
    return(last);
}