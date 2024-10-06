// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement the concept of deque.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#define size 6

int arr[size];
int front = -1, rear = -1;

void insert_from_front();
void insert_from_rear();
int delete_from_front();
int delete_from_rear();
void display();
void input_restricted();
void output_restricted();

int main()
{
    int choice, val;

    do
    {
        printf("\n ***** MAIN MENU ***** \n");
        printf("1. Input restricted queue \n");
        printf("2. Output restricted queue \n");
        printf("3. Display \n");
        printf("4. Exit \n");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch(choice)
        {
            case 1:
            input_restricted();
            break;

            case 2:
            output_restricted();
            break;

            case 3:
            display();
            break;

            case 4:
            break;
        }

    } while ( choice != 4);

    return 0;
}

void input_restricted()
{
    int val, choice1;

    printf(" \n ----- Input Restricted Queue ----- \n");

    do
    {
        printf("\n ***** Sub Menu **** \n");
        printf("1. Insert from rear \n");
        printf("2. Delete from front \n");
        printf("3. Delete from rear \n");
        printf("4. Display \n");
        printf("5. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice1);

        printf("\n");

        switch (choice1)
        {
            case 1:
            insert_from_rear();
            break;

            case 2:
            val = delete_from_front();
            if (val != -1)
            {
                printf("The value deleted is: %d \n", val);
            }
            break;

            case 3:
            val = delete_from_rear();
            if (val != -1)
            {
                printf("The value deleted is: %d \n", val);
            }
            break;

            case 4:
            display();
            break;

            case 5:
            break;
        }

    } while (choice1 != 5);
}

void output_restricted()
{
    int val, choice2;

    printf("\n ----- Output Restricted Queue ----- \n");

    do
    {
        printf("\n ***** Sub Menu ***** \n");
        printf("1. Insert from front \n");
        printf("2. Insert from rear \n");
        printf("3. Delete from front \n");
        printf("4. Display \n");
        printf("5. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice2);

        printf("\n");

        switch(choice2)
        {
            case 1:
            insert_from_front();
            break;

            case 2:
            insert_from_rear();
            break;

            case 3:
            val = delete_from_front();
            if (val != -1)
            {
                printf("The value deleted is %d \n", val);
            }
            break;

            case 4:
            display();
            break;

            case 5:
            break;
        }
    } while (choice2 != 5);
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

        for(i=front; i!=rear; i = (i + 1) % size)
        {
            printf("\t %d", arr[i]);
        }
        printf("\t %d", arr[i]);
    }
    printf("\n");
}

void insert_from_rear()
{
    int val;

    printf("Enter value: ");
    scanf("%d", &val);

    if ( (rear + 1)%size == front )
    {
        printf("Queue is full \n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        arr[front] = val;
        printf("Successfully inserted from rear \n");
    }
    else
    {
        rear = (rear+1)%size;
        arr[rear] = val;
        printf("Successfully inserted from rear \n");
    }
}

void insert_from_front()
{
    int val;

    printf("Enter val: ");
    scanf("%d", &val);

    if ( (rear + 1) % size == front )
    {
        printf("Queue is full \n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        arr[front] = val;
        printf("Successfully inserted from front \n");
    }
    else
    {
        front = (front -1 + size) % size;
        arr[front] = val;
        printf("Successfully inserted from front \n");
    }
}

int delete_from_front()
{
    int val;

    if (front == -1)
    {
        printf("Queue is empty \n");
        return -1;
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
        front = rear = -1;
        return val;
    }
}

int delete_from_rear()
{
    int val;

    if (front == -1)
    {
        printf("Queue is empty \n");
        return -1;
    }
    else
    {
        val = arr[rear];
        rear = (rear - 1 + size) % size;
        return val;
    }
}

// g++ -g 4-3.cpp -o 4-3
// ./4-3
/*
$ ./4-3

 ***** MAIN MENU *****
1. Input restricted queue 
2. Output restricted queue
3. Display
4. Exit

 Enter your choice: 1


 ----- Input Restricted Queue -----

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 1

Enter value: 1
Successfully inserted from rear 

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 4

The Queue is:    1

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 1

Enter value: 2
Successfully inserted from rear 

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 4

The Queue is:    1       2

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 1

Enter value: 3
Successfully inserted from rear 

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 4

The Queue is:    1       2       3

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 5


 ***** MAIN MENU *****
1. Input restricted queue
2. Output restricted queue
3. Display
4. Exit

 Enter your choice: 2


 ----- Output Restricted Queue -----

 ***** Sub Menu *****
1. Insert from front
2. Insert from rear
3. Delete from front
4. Display
5. Exit
Enter your choice: 1

Enter val: 4
Successfully inserted from front 

 ***** Sub Menu *****
1. Insert from front
2. Insert from rear
3. Delete from front
4. Display
5. Exit
Enter your choice: 4

The Queue is:    4       1       2       3

 ***** Sub Menu *****
1. Insert from front
2. Insert from rear
3. Delete from front
4. Display
5. Exit
Enter your choice: 1

Enter val: 5
Successfully inserted from front 

 ***** Sub Menu *****
1. Insert from front
2. Insert from rear
3. Delete from front
4. Display
5. Exit
Enter your choice: 4

The Queue is:    5       4       1       2       3

 ***** Sub Menu *****
1. Insert from front
2. Insert from rear
3. Delete from front
4. Display
5. Exit
Enter your choice: 2

Enter value: 6
Successfully inserted from rear 

 ***** Sub Menu *****
1. Insert from front
2. Insert from rear
3. Delete from front
4. Display
5. Exit
Enter your choice: 4

The Queue is:    5       4       1       2       3       6   

 ***** Sub Menu *****
1. Insert from front
2. Insert from rear
3. Delete from front
4. Display
5. Exit
Enter your choice: 3

The value deleted is 5

 ***** Sub Menu *****
1. Insert from front
2. Insert from rear
3. Delete from front
4. Display
5. Exit
Enter your choice: 4

The Queue is:    4       1       2       3       6

 ***** Sub Menu *****
1. Insert from front
2. Insert from rear
3. Delete from front
4. Display
5. Exit
Enter your choice: 5


 ***** MAIN MENU *****
1. Input restricted queue
2. Output restricted queue
3. Display
4. Exit

 Enter your choice: 3

The Queue is:    4       1       2       3       6

 ***** MAIN MENU *****
1. Input restricted queue
2. Output restricted queue
3. Display
4. Exit

 Enter your choice: 1


 ----- Input Restricted Queue -----

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 3

The value deleted is: 6

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 3

The value deleted is: 3

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 4

The Queue is:    4       1       2

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 2

The value deleted is: 4

 ***** Sub Menu ****
1. Insert from rear
2. Delete from front
3. Delete from rear
4. Display
5. Exit
Enter your choice: 5


 ***** MAIN MENU *****
1. Input restricted queue
2. Output restricted queue
3. Display
4. Exit

 Enter your choice: 4
*/