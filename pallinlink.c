#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
    char data[20];
    struct node *next, *prev;
};
struct node *insert(struct node *head)
{
    struct node *nw;
    nw = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%s", nw->data);
    nw->prev = NULL;
    nw->next = NULL;

    if (head == NULL)
    {
        head = nw;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nw;
        nw->prev = temp;
    }
    return head;
}
void display(struct node *s)
{
    struct node *temp = s;
    while (temp->next != NULL)
    {
        printf("%s", temp->data);
        temp = temp->next;
        printf("->");
    }
    printf("%s\n", temp->data);
}
void checkpalin(struct node *head)
{
    if(head==NULL)
        printf("List empty\n");
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(ispalin(temp->data))
        {
            printf("%s is not Palin\n",temp->data);
        }
        else
            printf("%s is Palin\n",temp->data);
        temp=temp->next;
        
    }
}
int ispalin(char *str)
{
    int l=strlen(str)-1;
    int i,j,flag=0;
    for(i=0,j=l;i<l;i++,j--)
    {
        if((str[i])!=(str[j]))
        {
            flag=1;
            break;
        }
    }
        if(flag)
            return 1;
        else
            return 0;
    
    
}
int main()
{
    struct node *start = NULL;
    int ch;
    while (1)
    {
        printf("\nEnter\n1. Insert\n2. Display\n3. CheckPalin\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start = insert(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            checkpalin(start);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}