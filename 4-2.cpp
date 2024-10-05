// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement the concept of circular queue.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#define size 5

int arr[5];
int front = -1, rear = -1;

void insert();  // Insert an element in the queue
int deleteq();  // Delete an element in the queue
void display(); // Display all the element from front to rear

int main()
{
    int choice, val;

    do
    {
        printf("***** MAIN MENU ***** \n");
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Display \n");
        printf("4. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
            case 1: 
            insert();
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

    printf("Enter value to insert: ");
    scanf("%d", &val);

    if ( (rear + 1) % size == front )
    {
        printf("Queue is full \n\n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        arr[front] = val;
        printf("Sucessfully inserted \n\n");
    }
    else
    {
        rear = (rear + 1) % size;
        arr[rear] = val;
        printf("Successfully inserted \n\n");
    }
}

int deleteq()
{
    int val;

    if (front == -1)
    {
        printf("Queue is empty \n");
    }
    else if (front != rear)
    {
        val = arr[front];
        front = (front + 1) % size;
        return val;
    }
    else
    {
        val = arr[front];
        front = -1;
        rear = -1;
        return val;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The Queue is: ");

        for (i = front; i != rear; i = (i+1) % size)
        {
            printf("\t %d", arr[i]);
        }
        printf("\t %d", arr[i]); // prints the last element in the arr
    }
    printf("\n");
}