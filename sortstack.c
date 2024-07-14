// sort stack
#include<stdio.h>
#define MAX 10
struct stack{
    int data[MAX];
    int top;
};
void push(struct stack *st,int x);
int pop(struct stack *st);
void sortstack(struct stack *stk);
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
    sortstack(&stk);
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
void sortstack(struct stack *stk)
{
    struct stack tstk;
    tstk.top=-1;
    int temp=pop(stk);
    push(&tstk,temp);
    while(!isempty(stk))
    {
        int t=pop(stk);
        if(t>(peek(tstk)))
        {
            push(&tstk,t);
        }
        else
        {
            while(!isempty(&tstk)  && t<(peek(tstk)))
            {
                 int s=pop(&tstk);
                 push(stk,s);
            }
            push(&tstk,t);
        }
              
    }
    while(!isempty(&tstk))
    {
        int shift=pop(&tstk);
        push(stk,shift);
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