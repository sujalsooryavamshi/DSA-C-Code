#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* insertE(struct node *head,int x);
void displayprime(struct node *head);
void display(struct node *head);
struct node * deletealter(struct node *head);
struct node* deletespecific(struct node *head);
struct node *insertB(struct node *head)
{
    int x;
    printf("enter the data to insert at the begin\n");
    scanf("%d",&x);
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        new->next=head;
        head=new;
    }
    return(head);
}
struct node *deleteE(struct node *head)
{
    struct node *temp,*prev;
      if(head==NULL)
       printf("Empty list\n");
      if(head->next==NULL)
      {
          temp=head;
          head=NULL;
          free(temp);
          return(head);
      }
      else
      {
          temp=prev=head;
          while(temp->next!=NULL)
          {
              prev=temp;
              temp=temp->next;
          }
          prev->next=NULL;
          free(temp);
      }
      return head;
}
struct node*deleteB(struct node *head)
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
         temp=head;
         head=head->next;
         free(temp);
    }
    return(head);
}
void occurance(struct node *head)
{
    int cnt=0,ele;
    struct node *temp;
    if(head==NULL)
     printf("empty list\n");
     else
     {
         printf("Enter the ele to search\n");
         scanf("%d",&ele);
         while(temp!=NULL)
         {
             if(temp->data==ele)
               ++cnt;
            temp=temp->next;
         }
         printf("The number of occur is %d\n",cnt);
     }
}
main()
{
    struct node *head=NULL;
    int x,ch;
    printf("Enter 1 to insert and 2 to displayprime 3 to delete alter 4 to diplay 5 to delete speci and 6 to insertB,7 to deleteE,8 to deleteB ,9 to occur,10 to exit\n");
    while(1)
    {
        printf("\nEnter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data to insert at the end\n");
                   scanf("%d",&x);
                   head=insertE(head,x);
                   break;
                
            case 2: displayprime(head);
                    break;
            case 3: head= deletealter(head);
                    break;
            case 4: display(head);
                    break;
            case 5: head= deletespecific(head);
                    break;
            case 6: head=insertB(head);
                    break;
            case 7: head=deleteE(head);
                    break;
            case 8: head=deleteB(head);
                    break;
            case 9: occurance(head);
                    break;
            case 10:exit(0);
            
        }
          
    }
}
struct node* insertE(struct node *head,int x)
{
    struct node *temp;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    if(head==NULL)
    {
        head=temp=new;
    }
    else
     {
        temp=head;
         while(temp->next!=NULL)
           temp=temp->next;
         temp->next=new;
     }
     return(head);
}
void displayprime(struct node *head)
{
    if(head==NULL)
      printf("empty list\n");
    else
     {
        struct node *temp=head;
        while(temp!=NULL)
        {
             int flag=1;
             int res=temp->data/2;
             for(int i=2;i<=res;++i)
             {
                  if(temp->data%i==0)
                  {
                       flag=0;
                       break;
                  }
             }
             if(flag==1 && temp->data>1)
               printf("%d\t",temp->data);
        
          temp=temp->next;
        }
     }
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("the display function is \n");
         struct node *temp=head;
         while(temp!=NULL)
         {
             printf("%d\t",temp->data);
             temp=temp->next;
         }
    }
}
struct node* deletealter(struct node *head)
{
    if(head==NULL)
     printf("empty list \n");
    else
      {
         struct node *temp,*trav;
         temp=head;
        while(temp!=NULL && temp->next!=NULL)
       {
           trav=temp->next;
           temp->next=trav->next;
           free(trav);
           temp=temp->next;
       }
      }
      return(head);
}
struct node* deletespecific(struct node *head)
{
    int data;
    struct node *temp,*prev;
    temp=prev=head;
    printf("Enter the data to delete\n");
    scanf("%d",&data);
    if(head==NULL)
     printf("The list is empty\n");
    else
    {
        if(head->data==data)
        {
             temp=head;
             head=head->next;
             free(temp);
             return(head);
        }
       else if(head->next==NULL)
        {
             printf("No element found\n");
        }
        else
         {
            temp=head->next;
             while(temp!=NULL)
             {
                if(temp->data==data)
                {
                     prev->next=temp->next;
                     free(temp);
                     break;
                }
                prev=temp;
                temp=temp->next;
             }
             if(temp==NULL)
              printf("Element not found\n");
         }
      return(head);  
    }
}
