#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// postfix to infix
#define max 100
char stack[max][max];
int top = -1;
int isspaces(char c);
int isempty();
void push(char symbol[]);
void pop(char symbol[]);
void posttoin(char post[]);


main() {  
    char post[100];
    printf("Enter the postfix expression without spaces:\n");
    scanf("%s", post);
    posttoin(post);
    return 0;
}

void posttoin(char post[]) {
    int i, l = strlen(post);
    int posIndex = 0;

    for (i = 0; i < l; ++i) {
        char c = post[i];

        if (!isspaces(c)) 
        {
            if (isalpha(c))
             {
                char temp[1];
                temp[0] = c;
                push(temp);
            }
             else 
            {
                char a[max], b[max];
                pop(a);
                pop(b);
                char temp[max];               
                if(c == '+' || c == '-' || c == '*' || c == '/') {
                    sprintf(temp, "(%s%c%s)", b, c, a);
                } else if (c == '^') {
                    sprintf(temp, "%s%c(%s)", b, c, a);
                }

                push(temp);
            }
        }
    }
    char result[max];
    pop(result);
    printf("%s",result);
    
}

int isspaces(char c) {
    
    if( c == ' ' || c == '\t')
     return(1);
     else
      return(0);
}

int isempty() {
    return top == -1;
}

void push(char symbol[]) {
    if (top == max - 1) {
        printf("Over flow condition\n");
    } else {
        top++;
        strcpy(stack[top], symbol);
    }
}

void pop(char symbol[]) {
    if (top == -1) {
        printf("Underflow condition\n");
        exit(1);
    } else {
        strcpy(symbol, stack[top]);
        top--;
    }
}
