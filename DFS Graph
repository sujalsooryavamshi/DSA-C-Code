#include <stdio.h>
#include <stdlib.h>

#define MAX 8

struct stack {
    int top;
    int data[MAX];
};

void push(struct stack *s, int x);
int pop(struct stack *s);
int is_empty(struct stack *s);

void DFS(int adj[MAX][MAX], int start);

int main() {
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
    };

    int i = 0; //source node
    printf("DFS starting from vertex %d:\n",i);
    DFS(adj,i);

    return 0;
}

void push(struct stack *s, int x) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }

    s->data[++s->top] = x;
}

int pop(struct stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        return -1;
    }

    return s->data[s->top--];
}

int is_empty(struct stack *s) {
    return s->top == -1;
}

void DFS(int adj[MAX][MAX], int source) {
    struct stack s;
    s.top = -1;

    int visited[MAX] = {0};

    push(&s, source);
    visited[source] = 1;
    while (!is_empty(&s)) {
        int node = pop(&s);
        printf("%d\t", node);

        for (int j = MAX - 1; j >= 0; --j) {
            if (adj[node][j] == 1 && !visited[j]) {
                push(&s, j);
                visited[j] = 1;
            }
        }
    }

    printf("\n");
}
