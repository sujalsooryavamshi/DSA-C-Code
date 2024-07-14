
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *insert(struct node *head);
void display(struct node *head);
void check(struct node *head);
int prime(int data);

int main() {
    struct node *head = NULL;
    int ch;
    printf("\nEnter\n 1 to insert\n 2 to display\n 3 check prime\n 4 to exit\n");
    while (1) {
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                head = insert(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                check(head);
                break;
            case 4:
                exit(0);
        }
    }
}

struct node *insert(struct node *head) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
        head = newNode;
    else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

void display(struct node *head) {
    if (head == NULL)
        return;
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void check(struct node *head) {
    if (head == NULL)
        return;
    struct node *temp = head;
    while (temp != NULL) {
        if (prime(temp->data))
            printf("%d is prime\n", temp->data);
        temp = temp->next;
    }
}

int prime(int data) {
    if (data == 1)
        return 0;
    for (int i = 2; i <= data / 2; ++i) {
        if (data % i == 0) {
            return 0;
        }
    }
    return 1;
}
