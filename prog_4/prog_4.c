#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* createNode(int value) {
    struct node* n = malloc(sizeof(struct node));
    n->data = value;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void insertAfter(struct node* target, int value) {
    if (target == NULL) return;
    
    struct node* newNode = createNode(value);
    newNode->next = target->next;
    newNode->prev = target;
    
    if (target->next != NULL) {
        target->next->prev = newNode;
    }
    target->next = newNode;
}

void deleteNode(struct node** head, struct node* del) {
    if (*head == NULL || del == NULL) return;
    
    if (*head == del) {
        *head = del->next;
    }
    
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }
    
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }
    
    free(del);
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = createNode(10);
    struct node* second = createNode(20);
    struct node* third = createNode(30);
    
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    
    printf("Original list: ");
    display(head);
    
    insertAfter(second, 25);
    printf("After inserting 25 after 20: ");
    display(head);
    
    deleteNode(&head, second);
    printf("After deleting 20: ");
    display(head);
    
    return 0;
}