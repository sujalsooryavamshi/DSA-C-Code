// check validity
#include<stdio.h>
#define size 10
int top =-1;
char stack[size];
void push(char ch);
char pop();
main()
{
    int i;
    char str[25],temp;
    printf("Enter the expression\n");
    scanf("%s",str);
    for(i=0;str[i]!='\0';++i)
    {
         if(str[i]=='[' || str[i]=='{' || str[i]=='(')
             push(str[i]);
         else if(str[i]==']'|| str[i]==')' || str[i]=='}'){
           temp=pop();
           switch(str[i])
           {
              case ']' :if( temp!='['){
                         printf("Invalid\n");
                         return(0);
                        }
                         break;
              case '}' : if( temp!='{'){
                        printf("invalid\n");
                         return(0); 
                         }
                          break;
              case ')' : if(temp!='(')
                         {
                          printf("invalid\n");
                          return(0);
                         }
                          break;
           }
         }
    }
    if(top==-1)
       printf("valid\n");
    else
      printf("Invalid");
}
void push(char ch)
{
    if(top==size-1)
      printf("overflow");
    else
      stack[++top]=ch;
}
char pop()
{
    char temp;
    if(top==-1)
     printf("underflow");
    else
    {
      temp=stack[top];
       --top;
       return(temp);
    }
}