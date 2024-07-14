// check pallindrome stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
struct stack{
    char data[MAX];
    int top;
};
void push(struct stack *st,char x);
char pop(struct stack *st);
char *revstring(char str[]);
int isempty(struct stack *s);
void display(struct stack stk);
int peek(struct stack st);
main()
{
   char str[50];
   printf("Enter the string \n");
   scanf("%s",str);
   printf("%s",revstring(str));
   
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
char * revstring(char str[])
{
    struct stack stk;
    stk.top=-1;
    int l=strlen(str),j=0;
    for(int i=0;i<l;++i)
    {
         push(&stk,str[i]);
    }
    while(!isempty(&stk))
    {
         str[j]=pop(&stk);
         ++j;
    }
    return(str);
}

int isempty(struct stack *s)
{
    if(s->top==-1)
     return(1);
    else
      return(0);
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