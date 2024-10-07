// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement selection sort.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

int arr[20];

void selection_sort(int n)
{
    int imin, i, j, temp;

    for (i=0; i<n; i++)
    {
        imin = i;

        for (j=i+1; j<n; j++)
        {
            if (arr[imin] > arr[j])
            {
                imin = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[imin];
        arr[imin] = temp;
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

    selection_sort(n);

    printf("After sorting using selection sort: ");

    for (i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }
}

// Output:-
/*
$ ./5-2
Enter number of elements: 5
Enter 0 th element: 4
Enter 1 th element: 3
Enter 2 th element: 5
Enter 3 th element: 2
Enter 4 th element: 1
After sorting using selection sort       1       2     3       4       5 
*/