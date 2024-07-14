#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
main()

{
    struct node *head,*newnode,*temp;
    int choice,cnt=0;
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
       printf("The address of new node are %d\n",temp->next);
       temp=temp->next;
       ++cnt;
    }
    printf("The number of nodes created are %d\n",cnt);
      
}