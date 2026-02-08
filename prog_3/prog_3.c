#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int value;
    struct ListNode* nextNode;
} ListNode;

typedef struct {
    ListNode* first;
    int count;
} LinkedList;

void initializeList(LinkedList* list) {
    list->first = NULL;
    list->count = 0;
}

ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = val;
    newNode->nextNode = NULL;
    return newNode;
}

void insertAtEnd(LinkedList* list, int val) {
    ListNode* newNode = createNode(val);
    
    if (list->first == NULL) {
        list->first = newNode;
    } else {
        ListNode* current = list->first;
        while (current->nextNode != NULL) {
            current = current->nextNode;
        }
        current->nextNode = newNode;
    }
    list->count++;
}

void displayReverse(ListNode* current) {
    if (current == NULL) {
        return;
    }
    displayReverse(current->nextNode);
    printf("%d ", current->value);
}

void displayForward(ListNode* current) {
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->nextNode;
    }
}

void freeList(LinkedList* list) {
    ListNode* current = list->first;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->nextNode;
        free(temp);
    }
    list->first = NULL;
    list->count = 0;
}

int main(void) {
    LinkedList myList;
    initializeList(&myList);
    
    insertAtEnd(&myList, 10);
    insertAtEnd(&myList, 20);
    insertAtEnd(&myList, 30);
    insertAtEnd(&myList, 40);
    insertAtEnd(&myList, 50);
    
    printf("Forward Traversal: ");
    displayForward(myList.first);
    printf("\n");
    
    printf("Reverse Traversal: ");
    displayReverse(myList.first);
    printf("\n");
    
    printf("Total nodes: %d\n", myList.count);
    
    freeList(&myList);
    
    return 0;
}