#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct ListNode {
    int data;
    struct ListNode* prev;
    struct ListNode* next;
};

// Function to delete duplicates in a doubly linked list
void delete_duplicates(struct ListNode** head) {
    if (*head == NULL) {
        return;
    }

    struct ListNode* current = *head;

    while (current != NULL) {
        struct ListNode* runner = current->next;

        while (runner != NULL) {
            if (current->data == runner->data) {
                struct ListNode* duplicate = runner;
                runner->prev->next = runner->next;

                if (runner->next != NULL) {
                    runner->next->prev = runner->prev;
                }

                free(duplicate);
            }

            runner = runner->next;
        }

        current = current->next;
    }
}

// Function to print a doubly linked list
void print_list(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to create a new node for the doubly linked list
struct ListNode* create_node(int data) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Main function for testing the delete_duplicates function
int main() {
    // Create a doubly linked list with duplicates
    struct ListNode* head = create_node(1);
    head->next = create_node(2);
    head->next->prev = head;
    head->next->next = create_node(3);
    head->next->next->prev = head->next;
    head->next->next->next = create_node(2);
    head->next->next->next->prev = head->next->next;

    printf("Original List: ");
    print_list(head);

    // Delete duplicates
    delete_duplicates(&head);

    printf("List after deleting duplicates: ");
    print_list(head);

    // Free the allocated memory for the linked list
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
