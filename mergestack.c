#include <stdio.h>
#include <stdlib.h>
// merge two stacks
struct stack {
    int data;
    struct stack *next;
    struct stack *top, *tail;
};

void push(struct stack *s, int x);
int pop(struct stack *s1);
struct stack *merge(struct stack *s1, struct stack *s2);
void display(struct stack *s3);

int main() {
    int x;
    struct stack s1, s2, *s3;
    s1.top = s1.tail = NULL;
    s2.top = s2.tail = NULL;
    push(&s1, 20);
    push(&s1, 30);
    push(&s1, 40);
    push(&s2, 50);
    push(&s2, 60);
    push(&s2, 70);
    s3 = merge(&s1, &s2);
    display(s3);
    x = pop(s3);
    display(s3);
    printf("The popped element is %d\n", x);

    return 0;
}

void push(struct stack *s, int x) {
    struct stack *new;
    new = (struct stack *)malloc(sizeof(struct stack));
    new->data = x;
    if (s->top == NULL) {
        s->top = new;
        s->tail = new;
        new->next = NULL;
    } else {
        new->next = s->top;
        s->top = new;
    }
}

int pop(struct stack *s1) {
    int x;
    struct stack *temp;
    if (s1->top == NULL) {
        printf("Stack is empty\n");
        return -1; 
    } else {
        temp = s1->top;
        x = temp->data;
        s1->top = temp->next;
        free(temp);
        return x;
    }
}

struct stack *merge(struct stack *s1, struct stack *s2) {
    if (s1->top == NULL)
        return s2;
    if (s2->top == NULL)
        return s1;

    struct stack *merge = (struct stack *)malloc(sizeof(struct stack));
    merge->top = s1->top;
    merge->tail = s2->tail;
    s1->tail->next = s2->top;
    merge->top = s1->top;
    return merge;
}

void display(struct stack *s3) {
    printf("After merging the stack:\n");
    struct stack *temp = s3->top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
