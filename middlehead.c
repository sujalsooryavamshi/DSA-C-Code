 #include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *middlehead(struct node *s);
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
    printf("The adress of first node stored in head is %d\n",head);
    while(temp!=NULL)
    {
       printf("%d\n",temp->data);
       temp=temp->next;
    }
   head= middlehead(head);
   temp=head;
   printf("After alteration the middel element is head\n");
   while(temp!=NULL)
   {
      printf("%d\n",temp->data);
      temp=temp->next;
   }   
      
}
struct node *middlehead(struct node *s)
{
    struct node *temp,*slow,*fast;
    if(s==NULL)
      printf("Empty set\n");
   else  if(s->next==NULL)
      return(s->next);
    else 
    {
       fast=s;
       slow=s;
       while(fast!= NULL && fast->next!=NULL)
       {  
           fast=fast->next->next;
           temp=slow;
           slow=slow->next;
       }
       temp->next=slow->next;
       slow->next=s;
       s=slow;
    }
       return(s);
}
