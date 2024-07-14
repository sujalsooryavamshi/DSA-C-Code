#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to double a number represented as a linked list
void doubleNumber(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        current->data *= 2;
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Example: Represent the number 123 as a linked list
    struct Node* number = NULL;
    insertEnd(&number, 1);
    insertEnd(&number, 2);
    insertEnd(&number, 3);

    printf("Original Number: ");
    printList(number);

    // Double the number
    doubleNumber(number);

    printf("Doubled Number: ");
    printList(number);

    // Free the allocated memory
    freeList(number);

    return 0;
}
