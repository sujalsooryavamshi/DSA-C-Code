#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data[50];
    struct node *next;
};
void stringsort(struct node *s);
main()
{
    struct node *head,*newnode,*temp;
    int choice,cnt=0;
    head=0;
    while(choice)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the word\n");
    scanf("%s",newnode->data);
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
       printf("%s\n",temp->data);
       temp=temp->next;
    }
      stringsort(head);
}
void stringsort(struct node *s)
{
    char swap[50];
    struct node *temp,*run;
    if(s==NULL)
     {
        printf("The list is empty\n");
     }
     else if(s->next==NULL)
       printf("The list has only one word\n");
    else
    {
      for(temp=s;temp!=NULL;temp=temp->next)
       for(run=s;run->next!=NULL;run=run->next)
       {
              if(strcmp(run->data,run->next->data)>0)
              {
                    strcpy(swap,run->next->data);
                    strcpy(run->next->data,run->data);
                    strcpy(run->data,swap);
              }
       }
    }
    temp=s;
    printf("The orderd list is \n");
    while(temp!=NULL)
    {
        printf("%s\n",temp->data);
        temp=temp->next;
    } 
}