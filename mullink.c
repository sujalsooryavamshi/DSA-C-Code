#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int multiple(struct node *s);
main()
{
    struct node *head,*newnode,*temp;
    int choice,s;
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
    s= multiple(head);
    if(s==0)
     printf("NOT the multiplication table\n");
    else
     printf("The mul num is %d\n",s);
}
int multiple(struct node *s)
{
    struct node *temp;
    int small;
    if(s==NULL)
       printf("Empty list\n");
    if(s->next==NULL)
       printf("Only one data present %d",s->data);
    else
    {
       small=s->data;
       temp=s;
       while(temp!=NULL)
       {
           if(temp->data < small)
              small=temp->data;
            temp=temp->next;
       }
    temp=s;
      while(temp!=NULL)
      {
         if(temp->data%small!=0)
         {
           return(0);
           break;
         }
         else
           return(small);
        temp=temp->next;
      }
    }   

}