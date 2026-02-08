# Reverse List Traversal Program

## What I Built
A linked list that can be printed backwards using recursion.

## Structures Used

**ListNode** - Contains integer value and pointer to next node

**LinkedList** - Has pointer to first node and count of total nodes

## Function Breakdown

`initializeList()` - Sets first node to NULL and count to 0

`createNode()` - Makes new node with malloc and sets value

`insertAtEnd()` - Adds node at list end by traversing to last node

`displayReverse()` - Recursive function that goes to end first, then prints while returning

`displayForward()` - Simple loop to print normally

`freeList()` - Cleans up memory

## How Recursion Works Here
The function calls itself until it hits NULL, then prints values as it returns back up the call stack. This naturally reverses the order.

## What main() Does
Creates list, adds five values (10, 20, 30, 40, 50), shows forward version, shows reverse version, prints total count, frees memory.

## Running the Program

Forward Traversal: 10 20 30 40 50 
Reverse Traversal: 50 40 30 20 10 
Total nodes: 5
