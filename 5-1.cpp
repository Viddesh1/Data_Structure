// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement bubble sort.
// ------------------------------------------------------------------------------------------------------------------------------------

#include<stdio.h>
#include<malloc.h>

int arr[20];

void bubblesort(int n)
{
    int i, j, temp;

    for (i=0; i<n; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &arr[i]);
    }

    bubblesort(n);

    printf("Bubble Sort: ");

    for (i=0; i<n; i++)
    {
        printf("\t %d", arr[i]);
    }
}

// Output
/*
$ ./5-1
Enter number of elements: 5
Enter 0th element: 4
Enter 1th element: 5
Enter 2th element: 2
Enter 3th element: 3
Enter 4th element: 1
Bubble Sort:     1       2       3       4       5  
*/