#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the priority queue
void enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    // If the queue is empty or the new node has higher priority
    if (*head == NULL || priority > (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        // Traverse the list to find the correct position to insert the new node
        while (temp->next != NULL && temp->next->priority > priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to remove and return the highest priority element from the queue
int dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

// Function to check if the priority queue is empty
int isEmpty(struct Node* head) {
    return (head == NULL);
}

// Function to display the elements of the priority queue
void display(struct Node* head) {
    if (head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue: ");
    while (head != NULL) {
        printf("(%d, %d) ", head->data, head->priority);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* pq = NULL;
    int choice, data, priority;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority to enqueue: ");
                scanf("%d %d", &data, &priority);
                enqueue(&pq, data, priority);
                break;

            case 2:
                if (!isEmpty(pq)) {
                    printf("Dequeued element: %d\n", dequeue(&pq));
                }
                break;

            case 3:
                display(pq);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}