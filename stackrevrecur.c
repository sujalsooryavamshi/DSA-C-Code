//stack reverse recursion
#include<stdio.h>
#define MAX 10
struct stack{
    int data[MAX];
    int top;
};
void push(struct stack *st,int x);
int pop(struct stack *st);
void reverse(struct stack *stk);
void insertbottom(struct stack *stk,int item);
int isempty(struct stack *s);
void display(struct stack stk);
int peek(struct stack st);
main()
{
    struct stack stk;
    stk.top=-1;
    push(&stk,10);
    push(&stk,5);
    push(&stk,25);
    push(&stk,50);
    push(&stk,30);
    reverse(&stk);
    display(stk);
}
void push(struct stack *st,int x)
{
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
void reverse(struct stack *stk)
{
    
    int temp;
    if(!isempty(stk))
    {
         temp=pop(stk);
     reverse(stk);

    insertbottom(stk,temp);
    } 
            

}
void insertbottom(struct stack *stk,int item)
{
    if(isempty(stk))
    {
      push(stk,item);
    }
   else
   {
    int t=pop(stk);
    insertbottom(stk,item);

    push(stk,t);
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
      printf("The reversed  list is as follows\n");
      i=stk.top;
      while(i>=0)
      {
         printf("%d\n",stk.data[i]);
         --i;
      }
    }
}
int peek(struct stack st)
{
    if(st.top==-1)
    {
        printf("No elements to peek\n");
    }
    else
    {
      int x=st.data[st.top];
      return(x);
    }
}