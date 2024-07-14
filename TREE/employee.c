#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employe {
    int id;
    char name[30];
    int salar;
    char dep[20];
    int exp;
    struct employe *next;
};

// Function to insert a new employee at the beginning of the list
struct employe* insert(struct employe *head) {
    struct employe *new = (struct employe *)malloc(sizeof(struct employe));
    if (new == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the name, id, salary, department, and experience:\n");
    scanf("%s %d %d %s %d", new->name, &new->id, &new->salar, new->dep, &new->exp);
    new->next = head; // Insert at the beginning

    return new; // Return the new head of the list
}

// Function to display employees of a given department
void displayDep(struct employe *head, const char *dep) {
    int flag = 1; // Initialize flag to 1 (no matching records found)
    struct employe *temp = head;

    if (head == NULL)
        printf("Empty\n");
    else {
        while (temp != NULL) {
            if (strcmp(temp->dep, dep) == 0) {
                flag = 0; // Matching record found
                printf("%s\t%d\t%d\t%s\t%d\n", temp->name, temp->id, temp->salar, temp->dep, temp->exp);
            }
            temp = temp->next;
        }
        if (flag)
            printf("No records found for the department %s\n", dep);
    }
}

// Function to display employees with experience less than or equal to a given value
void displayExp(struct employe *head, int value) {
    int flag = 1; // Initialize flag to 1 (no matching records found)
    struct employe *temp = head;

    if (head == NULL)
        printf("Empty\n");
    else {
        while (temp != NULL) {
            if (temp->exp <= value) {
                flag = 0; // Matching record found
                printf("%s\t%d\t%d\t%s\t%d\n", temp->name, temp->id, temp->salar, temp->dep, temp->exp);
            }
            temp = temp->next;
        }
        if (flag)
            printf("No records found with experience less than or equal to %d\n", value);
    }
}

int main() {
    struct employe *head = NULL;

    // Insert three employees for demonstration
    head = insert(head);
    head = insert(head);
    head = insert(head);

    // Display employees of a given department
    displayDep(head, "ISE");

    // Display employees with experience less than or equal to a given value
    displayExp(head, 14);

    return 0;
}
