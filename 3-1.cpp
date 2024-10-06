// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement the concept of the stack with push, pop, display and exit operations.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 30

int stack[MAX], top = -1;

void push();
int pop();
int peek();
void display();
int isempty();
int isfull();

int main()
{
    int choice, topmost, val;

    do
    {
        printf("\n ***** MAIN MENU ***** \n");
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Peek \n");
        printf("4. Display \n");
        printf("5. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 
            push();
            break;

            case 2:
            val = pop();
            
            if (val != -1)
            {
                printf("The value popped is %d \n", val);
            }
            break;

            case 3:
            topmost = peek();
            printf("The topmost element is %d\n", topmost);
            break;

            case 4:
            display();
            break;

            case 5:
            break;
        } 
    } while (choice != 5);

    return 0;
}

void push()
{
    int val;

    if ( isfull() )
    {
        printf("The Stack is full \n");
    }
    else
    {
        printf("Enter the value to be pushed: ");
        scanf("%d", &val);

        stack[++top] = val;

        printf("Successfully pushed \n");
    }
}

int pop()
{
    if ( isempty() )
    {
        printf("The stack is empty \n");
        return -1;
    }
    else
    {
        int val = stack[top];
        top--;

        return val;
    }
}

int peek()
{
    if ( isempty() )
    {
        printf("Stack is empty \n");
        return -1;
    }
    else
    {
        int val = stack[top];
        return val;
    }
}

void display()
{
    int i, j;

    if ( isempty() )
    {
        printf("Stack empty");
    }
    else
    {
        printf("The Stack is \n");

        for (i=top; i>=0; i--)
        {
            printf("\t %d", stack[i]);
        }
        printf("\n");
    }
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
    if (top == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// output
/*
$ ./3-1

 ***** MAIN MENU *****
1. Push 
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to be pushed: 1
Successfully pushed 

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to be pushed: 2
Successfully pushed 

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
The Stack is 
         2       1

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to be pushed: 3
Successfully pushed 

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to be pushed: 5
Successfully pushed 

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
The Stack is 
         5       3       2       1

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 3
The topmost element is 5

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to be pushed: 6
Successfully pushed 

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 3
The topmost element is 6

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
The value popped is 6 

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
The value popped is 5 

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
The value popped is 3 

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
The value popped is 2

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
The value popped is 1

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
The stack is empty

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
The stack is empty

 ***** MAIN MENU *****
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 5
*/