
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *doubleno(struct node *sp);
struct node*rever(struct node *sp);
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
    while(temp!=NULL)
    {
       printf("%d\n",temp->data);
       temp=temp->next;
    }
    head=rever(head);
    head=doubleno(head);
    head=rever(head);
    printf("after doubling the nodes the nodes\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
      
}
struct node*rever(struct node *sp)
{
    struct node *prev,*curr,*next;
    prev=NULL;
    curr=next=sp;
    while(next!=NULL)
    {
        next=next->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    sp=prev;
    return(sp);
}
struct node *doubleno(struct node *sp)
{
     int res,carry=0;
     struct node *temp;
     temp=sp;
     while(temp!=NULL)
     {
        res=temp->data*2+carry;
        temp->data= res%10;
        carry=res/10;
        temp=temp->next;
     }
     temp=sp;
     if(carry!=0)
     {
         struct node *new;
         new=(struct node*)malloc(sizeof(struct node));
         new->data=carry;
         new->next=NULL;
         while(temp->next!=NULL)
         {
            temp=temp->next;
         }
         temp->next=new;
     }
     return(sp);
     
}
