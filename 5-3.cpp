// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement insertion sort.
// ------------------------------------------------------------------------------------------------------------------------------------

#include<stdio.h>

int arr[20];

void insertion_sort(int n)
{
    int val, vacant, i;

    for (i=0; i<n; i++)
    {
        val = arr[i];
        vacant = i;

        while (arr[vacant - 1] > val && vacant != 0)
        {
            arr[vacant] = arr[vacant - 1];
            vacant = vacant - 1;
        }

        arr[vacant] = val;
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Enter %d th element: ", i);
        scanf("%d", &arr[i]);
    }

    printf("After insertion sort: ");

    insertion_sort(n);
    for(i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }
}

// Output
/*
$ ./5-3
Enter number of elements: 5
Enter 0 th element: 5
Enter 1 th element: 4
Enter 2 th element: 3
Enter 3 th element: 2
Enter 4 th element: 21
After insertion sort: 2         3       4       5       21
*/