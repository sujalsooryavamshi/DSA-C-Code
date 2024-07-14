#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];
int top=-1;
void push(){
    int x;
    printf("Enter the number\n");
     scanf("%d",&x);
    if(top==N-1){
        printf("overflow\n");
         }
    else
    top++;
    stack[top]=x;

}
void pop()
{   int y;
    if(top==-1){
        printf("underflow\n");
    }
    
       else{
       y=stack[top];
       top--;
    }
}

void peek(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else
    printf("%d\n",stack[top]);

}
void display(){
    int i;
    if(top==-1)
       printf("Empty list\n");
    else
      for(i=top;i>-1;i--){
          printf("%d\n",stack[i]);
    }
}
void main(){
    int ch;
    do{
    printf("Enter choice:\t1-push\t2-pull\t3-peek\t4-display\n");
    scanf("%d",&ch);
        switch(ch){
            case 1:
                     push();
                     break;
            case 2:pop();
                    break;
            case 3:peek();
                    break;
            case 4:display();
                    break;
            case 0: printf("Bye\n");
                      exit(0);
            default:printf("invalid");
        }
    }while(ch!=0);
    
}