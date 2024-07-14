#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *random;
};

struct node* createnode(struct node *head, int a) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *trav = head;
    
    newNode->data = a;
    newNode->next = NULL;
    newNode->random = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = newNode;
    }
    return head;
}

void display(struct node *head) {
    struct node *trav = head;
    while (trav != NULL) {
        printf("%d (Random: %d) -> ", trav->data, (trav->random != NULL) ? trav->random->data : -1);
        trav = trav->next;
    }
    printf("\n");
}

struct node *newnode(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;
    new->random = NULL;
    return new;
}
struct node* separate(struct node *head) {
    struct node *copy = head->next, *temp1 = head, *temp2 = head->next;
    
    while (temp1 != NULL) {
        temp1->next = temp1->next ? temp1->next->next : NULL;
        temp2->next = temp2->next ? temp2->next->next : NULL; //important
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return copy;
}

struct node* clone(struct node *head) {
    if (head == NULL)
        return NULL;

    struct node *curr1, *temp;
    curr1 = head;

    // Creating a copy of one by one node in zigzag manner
    while (curr1 != NULL) {
        temp = curr1->next;
        struct node *newNode = newnode(curr1->data);
        curr1->next = newNode;
        newNode->next = temp;
        curr1 = temp;
    }

    // Reset the current pointer to the beginning of the list
    curr1 = head;

    // Now joining random link
    while (curr1 != NULL) {
        if (curr1->next != NULL) {
            curr1->next->random = (curr1->random != NULL) ? curr1->random->next : NULL;
        }
        curr1 = curr1->next;
    }

    // Now separate copy and original linked list
    return separate(head);
}

int main() {
    struct node *head = NULL;
    int i = 1;

    while (i < 6) {
        head = createnode(head, i);
        ++i;
    }

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next;
    head->next->next->next->random = head->next;

    printf("Original Linked List:\n");
    display(head);

    struct node *clonedHead = clone(head);

    printf("\nCloned Linked List:\n");
    display(clonedHead);

    // Don't forget to free allocated memory when you're done
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    while (clonedHead != NULL) {
        temp = clonedHead;
        clonedHead = clonedHead->next;
        free(temp);
    }

    return 0;
}
