// delete middle of stack using recursion
#include<stdio.h>
#define MAX 10
struct stack{
    int data[MAX];
    int top;
};
void push(struct stack *st,int x);
int pop(struct stack *st);
int isempty(struct stack *s);
struct stack * demidrec(struct stack *stk,int m,int curr);
void display(struct stack stk);
int peek(struct stack *st);
main()
{
    int curr=0;
    struct stack stk;
    stk.top=-1;
    push(&stk,10);
    push(&stk,5);
    push(&stk,25);
    push(&stk,50);
    push(&stk,30);
    int m= stk.top;
    demidrec(&stk,m,curr);
    display(stk);
}
void push(struct stack *st,int x)
{
    if(st->top==MAX-1)
    {
        printf("stack is empty\n");
    }
   if(st->top==-1)
   {
      st->top=0;
      st->data[st->top]=x;
   }
   else
     st->data[++st->top]=x;
}
int pop(struct stack *st)
{
    if(st->top==0)
    {
        int x=st->data[st->top];
        st->top=-1;
        return(x);
    }
    else
    {
      int x=st->data[st->top--];
      return(x);
    }
}
int isempty(struct stack *s)
{
    if(s->top==-1)
     return(1);
    else
      return(0);
}
void display(struct stack stk)
{
    int i;
    if(stk.top==-1)
      printf("The stack is empty\n");
    else
    {
      printf("The sorted list is as follows\n");
      i=stk.top;
      while(i>=0)
      {
       printf("%d\n",stk.data[i]);
         --i;
      }
    }
}
struct stack * demidrec(struct stack *stk,int m,int curr)
{
    int x;
   if(isempty(stk) || curr==m)
     {
        return(0);
     }
    x=peek(stk);
    pop(stk);
    demidrec(stk,m,curr+1);
    if(curr!=m/2 && curr !=(m+1)/2)
      push(stk,x);

}
int peek(struct stack *st)
{
    if(st->top==-1)
    {
        printf("No elements to peek\n");
    }
    else
    {
      int x=st->data[st->top];
      return(x);
    }
}