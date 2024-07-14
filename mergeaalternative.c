#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeAlternately(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    
    while (l1 && l2) {
        current->next = l1;
        l1 = l1->next;
        current = current->next;
        
        current->next = l2;
        l2 = l2->next;
        current = current->next;
    }
    
    // If one of the lists is longer, append its remaining nodes
    if (l1) {
        current->next = l1;
    }
    if (l2) {
        current->next = l2;
    }
    
    return dummy.next;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create two sample linked lists
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    
    for (int i = 10; i >= 1; i--) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = i;
        node->next = l1;
        l1 = node;
    }
    
    for (int i = 20; i >= 11; i--) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = i;
        node->next = l2;
        l2 = node;
    }
    
    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);
    
    struct ListNode* mergedList = mergeAlternately(l1, l2);
    
    printf("Merged List: ");
    printList(mergedList);
    
    // Free allocated memory to prevent memory leaks
    while (mergedList) {
        struct ListNode* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }
    
    return 0;
}

