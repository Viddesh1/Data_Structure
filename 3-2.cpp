// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to convert the infix expression to postfix expression.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[30], infix[30], postfix[30];
int top = -1;

int ifoperand(char a)
{
    if ((a >= '0' && a <= '9') || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ifoperator(char a)
{
    if (a == '%' || a == '*' || a == '/' || a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(char a)
{
    if (top == 29)
    {
        return 1;
    }
    else
    {
        top++;
        stack[top] = a;
        stack[top + 1] = '\0';
        return 0;
    }
}

int pop()
{
    char a;

    if (top == -1)
    {
        return 1;
    }
    else
    {
        a = stack[top];
        stack[top] = 0;
        top--;
        return a;
    }
}

int priority(char a)
{
    if (a == '%')
    {
        return 3;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int i, j, choice, answer;
    char a;

    printf("Enter the infix expression: \n");
    scanf("%s", infix);

    printf("Postfix expression after every iteration is: \n");

    for (i=0, j=0; i<strlen(infix); i++)
    {
        if (ifoperand(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (ifoperator(infix[i]))
        {
            while (strlen(stack) && priority(infix[i]) <= priority(stack[top]))
            {
                a = pop();
                if (a == '1')
                {
                    printf("The infix is wrong \n");
                    break;
                }
                postfix[j] = a;
                j++;
            }
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            a = pop();

            while (a != '(')
            {
                postfix[j] = a;
                j++;
                a = pop();
            }
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        printf("%s \n", postfix);
    }

    while (top > -1)
    {
        postfix[i] = pop();
        j++;
    }

    // postfix[j] = '\0';
    printf("The postfix expression is %s\n", postfix);

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
// The postfix expression is ab+cd*e+*f