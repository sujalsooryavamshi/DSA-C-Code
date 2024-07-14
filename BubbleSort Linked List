#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void sort(struct node *s);
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
       printf("The address of new node are %d\n",temp->next);
       temp=temp->next;
    }
    sort(head);     
}
void sort(struct node *s)
{
    struct node *temp,*run;
    int swap;
    if(s==NULL)
       printf("List is empty\n");
    else
    {
      for(temp=s;temp!=NULL;temp=temp->next)
        for(run=s;run->next!=NULL;run=run->next)
              if(run->data > run->next->data)
                 {
                      swap=run->next->data;
                      run->next->data=run->data;
                      run->data=swap;
                 }
    }
   printf("The sorted list is\n");
   temp=s;
   while(temp!=NULL)
   {
       printf("%d\n",temp->data);
       temp=temp->next;
   }
    
}
