# Doubly Linked List with Insert and Delete

## Overview
Doubly linked lists let you go both forward and backward because each node has two pointers.

## Node Structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

Each node knows about the node before and after it.

## Key Functions

**createNode()** - Makes new node with malloc, sets both pointers to NULL

**insertAfter()** - Inserts new node right after given node
- Links new node to target's next
- Updates previous/next pointers for all affected nodes

**deleteNode()** - Removes a node and fixes the links
- Updates previous node's next pointer
- Updates next node's previous pointer  
- Handles edge cases for head and tail

**display()** - Walks through list printing values

## Insert Algorithm
When inserting after a node, I need to update four pointers carefully to avoid breaking the chain.

## Delete Algorithm
Deletion is trickier because I have to check if deleting head or tail and update list pointers accordingly.

## Main Execution
Creates three nodes (10, 20, 30), demonstrates inserting after second node, then deletes the middle node.

## Output
Original list: 10 20 30 
After inserting 25 after 20: 10 20 25 30 
After deleting 20: 10 25 30