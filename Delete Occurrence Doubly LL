#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*pre;
};
struct node* deleteoccur(struct node *sp,int key);
main()
{   int choice,key;
    struct node *new,*head=NULL,*temp;
    printf("Enter the data\n");
    while(choice)
    {
      new=(struct node*)malloc(sizeof(struct node));
      scanf("%d",&new->data);
      new->pre=NULL;
      new->next=NULL;
      if(head==NULL)
      {
        head=temp=new;
      }
     else
     {
       temp->next=new;
       new->pre=temp;
       temp=new;
     }
    printf("Enter Choice \t");
    scanf("%d",&choice);
    }
    printf("Enter the key to be deleted\n");
    scanf("%d",&key);
    head=deleteoccur(head,key);
    temp=head;
    printf("After deleting the occurence of the given number\n");
    while(temp!=NULL)
    {
         printf("->%d",temp->data);
         temp=temp->next;
    }
}
struct node* deleteoccur(struct node *sp, int key) {
    struct node *temp, *prev, *fre;
    temp = sp;
    
    while (temp != NULL) {
        if (temp->data == key) {
            fre = temp;
            if (temp->pre != NULL) {
                temp->pre->next = temp->next;
            } else {
                sp = temp->next;  
            }
            if (temp->next != NULL) {
                temp->next->pre = temp->pre;
            }
            temp = temp->next;  
            free(fre);
        } else {
            prev = temp;
            temp = temp->next;  // Move to the next node
        }
    }
    
    return sp;
}

    


