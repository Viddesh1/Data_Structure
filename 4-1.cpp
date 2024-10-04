// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement the concept of the queue with insert, delete, display and exit operations.
// https://www.geeksforgeeks.org/queue-data-structure/
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int front = -1 , rear = -1;

void insert();
int deleteq();
void display();

int main()
{
    int choice, val;

    do
    {
        printf("******  MAIN MENU  ***** \n");
        printf("1. Insert an element \n");
        printf("2. Delete an element \n");
        printf("3. Display \n");
        printf("4. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch(choice)
        {
            case 1: insert();
            break;

            case 2:
            val = deleteq();
            if (val != -1)
            {
                printf("The value deleted is: %d \n", val);
            }
            break;

            case 3:
            display();
            break;

            case 4:
            break;
        }

    } while (choice != 4);

    return 0;
}

void insert()
{
    int val;
    
    printf("Enter value: ");
    scanf("%d", &val);

    if (rear == SIZE-1)
    {
        printf("Queue is full \n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = val;
        printf("Successfully inserted \n");
    }
    else
    {
        queue[++rear] = val;
        printf("Successfully inserted \n");
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty \n");
    }
    else 
    {
        printf("The queue is: ");

        for (i = front; i <= rear; i++) // Not actually deleting the element rather iterating through the queue
        {
            printf("\t %d", queue[i]);
        }

        printf("\n");
    }
}

int deleteq()
{
    int val;

    if (front == -1)
    {
        printf("Queue is empty \n");
        return -1;
    }
    else if (front == rear)
    {
        int val = queue[front];
        front = rear - 1;
        return val;
    }
    else
    {
        val = queue[front++];
        return val;
    }
}


// Output of the following code
/*
$ ./4-1
******  MAIN MENU  ***** 
1. Insert an element 
2. Delete an element 
3. Display 
4. Exit 
Enter your choice: 1 

Enter value: 1
Successfully inserted    
******  MAIN MENU  ***** 
1. Insert an element     
2. Delete an element     
3. Display 
4. Exit 
Enter your choice: 1     

Enter value: 2
Successfully inserted 
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 1

Enter value: 3
Successfully inserted 
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 1

Enter value: 4
Successfully inserted 
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 1

Enter value: 5
Successfully inserted 
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 3

The queue is:    1       2       3       4       5
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 2

The value deleted is: 1
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 2

The value deleted is: 2
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 3

The queue is:    3       4       5
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 1

Enter value: 6
Successfully inserted 
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 3

The queue is:    3       4       5       6
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 1

Enter value: 7
Queue is full
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 3

The queue is:    3       4       5       6
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 1

Enter value: 8
Queue is full
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 3

The queue is:    3       4       5       6
******  MAIN MENU  *****
1. Insert an element
2. Delete an element
3. Display
4. Exit
Enter your choice: 4
*/