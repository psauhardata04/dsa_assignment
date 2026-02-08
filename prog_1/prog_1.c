#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 100

typedef struct {
    char data[CAPACITY];
    int pointer;
} BracketStack;

void resetStack(BracketStack *s) {
    s->pointer = -1;
}

bool isEmpty(BracketStack *s) {
    return s->pointer == -1;
}

void insert(BracketStack *s, char bracket) {
    s->pointer++;
    s->data[s->pointer] = bracket;
}

char extract(BracketStack *s) {
    char element = s->data[s->pointer];
    s->pointer--;
    return element;
}

bool isPair(char left, char right) {
    switch(left) {
        case '(': return (right == ')');
        case '[': return (right == ']');
        case '{': return (right == '}');
        default: return false;
    }
}

bool isOpener(char c) {
    return (c == '(' || c == '[' || c == '{');
}

bool isCloser(char c) {
    return (c == ')' || c == ']' || c == '}');
}

bool validateExpression(char *expr) {
    BracketStack brackets;
    resetStack(&brackets);
    
    int position = 0;
    while (expr[position] != '\0') {
        char current = expr[position];
        
        if (isOpener(current)) {
            insert(&brackets, current);
        } 
        else if (isCloser(current)) {
            if (isEmpty(&brackets)) {
                return false;
            }
            char lastOpener = extract(&brackets);
            if (!isPair(lastOpener, current)) {
                return false;
            }
        }
        position++;
    }
    
    return isEmpty(&brackets);
}

void displayResult(char *expression) {
    bool result = validateExpression(expression);
    printf("%s -> %s\n", expression, result ? "Balanced" : "Not Balanced");
}

int main() {
    char expression1[] = "a + (b - c) * (d";
    char expression2[] = "m + [a - b * (c + d * {m)]";
    char expression3[] = "a + (b - c)";
    
    displayResult(expression1);
    displayResult(expression2);
    displayResult(expression3);
    
    return 0;
}