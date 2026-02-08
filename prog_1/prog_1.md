# Balanced Parentheses Checker - Documentation

## What This Program Does
This program checks if brackets in math expressions are balanced. It uses a stack to keep track of opening brackets and matches them with closing ones.

## How the Stack Works
I created a struct called `BracketStack` that has:
- A character array to store brackets
- An integer pointer to track the top position

When the pointer is -1, the stack is empty.

## Functions I Wrote

**resetStack()** - Sets pointer to -1 to make stack empty

**insert()** - Adds opening bracket to stack by incrementing pointer

**extract()** - Takes out the top bracket and decrements pointer

**isEmpty()** - Returns true if pointer equals -1

**isPair()** - Uses switch statement to check if brackets match like () or {} or []

**isOpener()** and **isCloser()** - Check if character is opening or closing bracket

**validateExpression()** - Goes through expression character by character, pushes opening brackets, pops and checks closing brackets

**displayResult()** - Calls validation and prints result

## How It Works
The program scans the expression from left to right. Opening brackets get pushed onto stack. When it finds a closing bracket, it pops from stack and checks if they match. At the end, if stack is empty, the expression is balanced.

## Main Function
I defined three test expressions and passed each one to displayResult() which tells if balanced or not.

## Sample Run
```
a + (b - c) * (d -> Not Balanced
m + [a - b * (c + d * {m)] -> Not Balanced
a + (b - c) -> Balanced
```