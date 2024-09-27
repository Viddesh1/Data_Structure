// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to convert the infix expression to prefix expression.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char expr[30];
char post[30];
char stack[30];
char temp[30];
int top = -1;

void push(float a);
float pop();
void intopostfix(char expr[]);
int preced(char a);
void reverse_expr(char str[]);

int main()
{
    int choice;
    float val;

    printf("Enter infix expression: ");
    scanf("%s", expr);

    reverse_expr(expr);
    intopostfix(temp);
    reverse_expr(post);

    printf("The prefix expression is: %s \n", temp);
}

void push(float a)
{
    stack[++top] = a;
}

float pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        float val = stack[top];
        top--;
        return val;
    }
}

void reverse_expr(char str[])
{
    int len, i = 0, j = 0;
    len = strlen(str);
    j = len - 1;

    while (j >= 0)
    {
        if (str[j] == '(')
        {
            temp[i] = ')';
        }
        else if (str[j] == ')')
        {
            temp[i] = '(';
        }
        else
        {
            temp[i] = str[j];
        }
    
        i++;
        j--;
    }

    temp[i] = '\0';
}

void intopostfix(char expr[30])
{
    char a;
    int i = 0, j = 0;

    while (expr[i] != '\0')
    {
        a = expr[i];

        if (a == '(')
        {
            push(a);
        }
        else if (isdigit(a))
        {
            post[j] = a;
            j++;
        }
        else if (isalpha(a))
        {
            post[j] = a;
            j++;
        }
        else if (a == ')')
        {
            while (stack[top] != '(' && top != -1)
            {
                post[j] = pop();
                j++;
            }

            if (stack[top] == '(')
            {
                top--;
            }
            else if (top == -1)
            {
                printf("Incorrect expression");
            }
        }
        else if (a == '+' || a == '-' || a == '*' || a == '/' || a == '%')
        {
            if (preced(a) >= preced(stack[top]))
            {
                push(a);
            }
            else
            {
                while (preced(a) < preced(stack[top]))
                {
                    post[j] = pop();
                    j++;
                }

                push(a);
            }
        }
        else
        {
            printf("Invalid character");
        }
        i++;
    }
    while (top != -1)
    {
        post[j] = pop();
        j++;
    }
}

int preced(char a)
{
    if (a == '+' || a == '-')
    {
        return 1;
    }
    else if (a=='*' || a=='/')
    {
        return 2;
    }
    else if (a == '%')
    {
        return 3;
    }
    else if (a == '(')
    {
        return 0;
    }
}

// The Output of the following code:

/*  
Enter infix expression: (A*B+C)-((D+E)/F-G)
The prefix expression is: -+*ABC-/+DEFG
*/