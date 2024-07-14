
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *removeloop(struct node *s);
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
    head=removeloop(head);
    printf("Removing the nodes\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
      
}
struct node *removeloop(struct node *s)
{
    struct node *trav,*prev,*current;
    if(s==NULL)
      return(0);
    else if(s->next==NULL)
      return(s);
    else
      current=s;
      while(current!=NULL)
      {
        prev=current;
        trav=current->next;
            while(trav!=NULL)
            {
                  if(prev->data == trav->data)
                     {
                          prev->next=trav->next;
                          free(trav);
                           trav=prev->next;
                      }
                    else{
                          prev=trav;
                          trav=trav->next;
                        }
            }
            current=current->next;           
      }
      return(s);
}