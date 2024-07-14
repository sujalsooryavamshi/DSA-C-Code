// check pallindrome stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
struct stack{
    char data[MAX];
    int top;
};
void push(struct stack *st,char x);
char pop(struct stack *st);
void pallin();
int isempty(struct stack *s);
void display(struct stack stk);
int peek(struct stack st);
main()
{
   printf("Enter the string \n");
   pallin();
}
void push(struct stack *st,char x)
{
   if(st->top==-1)
   {
      st->top=0;
      st->data[st->top]=x;
   }
   else
     st->data[++st->top]=x;
}
char pop(struct stack *st)
{
    if(st->top==0)
    {
        char x=st->data[st->top];
        st->top=-1;
        return(x);
    }
    else
    {
      char x=st->data[st->top--];
      return(x);
    }
}
void pallin()
{ 
    char str[50];
    struct stack stk;
    stk.top=-1;
    scanf("%s",str);
     int l=(strlen(str))/2;
     
     for(int i=0;i<l;++i)
     {
         push(&stk,str[i]);
     }
     for(int i=l+(strlen(str)%2);str[i]!='\0';++i)
     {
         if(str[i]!=pop(&stk))
         {
             printf("Its not the pallindrome \n");
             exit(0);
         }
     }
     printf("It is pallindrome\n");
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