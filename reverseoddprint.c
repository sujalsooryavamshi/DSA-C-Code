#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void revoddpri(struct node *s,int cnt);
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
    printf("The order is\n");
    revoddpri(head,cnt);   
}
void revoddpri(struct node *s,int cnt)
{
    if(s!=NULL)
    
      revoddpri(s->next,++cnt);
    
    if(cnt%2!=0)
    {
      printf("%d\n",s->data);
    }
      
    
    
}