// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to convert the infix expression to postfix expression.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[30], infix[30], postfix[30];
int top = -1;

int ifoperand(char a) {
    return isalnum(a); // Check if it's an alphanumeric character (operand)
}

int ifoperator(char a) {
    return (a == '%' || a == '*' || a == '/' || a == '+' || a == '-');
}

void push(char a) {
    if (top == 29) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = a;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1; // Error value
    } else {
        return stack[top--];
    }
}

int priority(char a) {
    switch (a) {
        case '%': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int main() {
    int i, j;
    char a;

    printf("Enter the infix expression: \n");
    scanf("%s", infix);

    printf("Postfix expression after every iteration is: \n");

    for (i = 0, j = 0; i < strlen(infix); i++) {
        if (ifoperand(infix[i])) {
            postfix[j++] = infix[i]; // Add operand to postfix
        } else if (infix[i] == '(') {
            push(infix[i]); // Push opening bracket
        } else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(') {
                postfix[j++] = pop(); // Pop till opening bracket
            }
            pop(); // Remove the '(' from the stack
        } else if (ifoperator(infix[i])) {
            while (top > -1 && priority(infix[i]) <= priority(stack[top])) {
                postfix[j++] = pop(); // Pop operators with higher or equal precedence
            }
            push(infix[i]); // Push the current operator
        }
        postfix[j] = '\0'; // Null-terminate for printing the postfix after each iteration
        printf("%s \n", postfix); // Print postfix after each step
    }

    // Pop the remaining operators from the stack
    while (top > -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the final postfix expression
    printf("The final postfix expression is %s\n", postfix);

    return 0;
}

// Output of the following code:

// Enter the infix expression:
// ((a+b)*(c*d+e))/f
// Postfix expression after every iteration is:


// a
// a
// ab
// ab+
// ab+
// ab+
// ab+c
// ab+c
// ab+cd
// ab+cd*
// ab+cd*e
// ab+cd*e+
// ab+cd*e+*
// ab+cd*e+*
// ab+cd*e+*f
// The final postfix expression is ab+cd*e+*f/