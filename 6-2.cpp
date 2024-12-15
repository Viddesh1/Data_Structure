// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement sequential search.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

#define SIZE 30

int a[SIZE], n;

int sequential(int a[], int val);

int sequential(int a[], int val)
{
    int i;

    for (i=0; i<n; i++)
    {
        if (a[i] == val)
        {
            return i;
        }
    }

    if (i == n)
    {
        return -1;
    }
}

int main()
{
    int choice = 0, val = 0, i, pos;
    char op = 'y';

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Enter a value: \t");
        scanf("%d", &a[i]);
    }

    while (op != 'n')
    {
        printf("\n Enter value to be searched: \t");
        scanf("%d", &val);

        pos = sequential(a, val);

        if (pos == -1)
        {
            printf("\n Value not found \n");
        }
        else
        {
            printf("Value found at position %d \n", (pos + 1));
            printf("Do you want to continue? \n");

            scanf(" %c", &op);
        }

        return 0;
    }
}

// Output
/*
$ ./6-2
Enter the number of elements: 5
Enter a value:  1
Enter a value:  3
Enter a value:  2
Enter a value:  5
Enter a value:  4

 Enter value to be searched:    4
Value found at position 5
Do you want to continue?
y
*/