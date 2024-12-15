// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to search the element using binary search.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#define SIZE 30

int a[SIZE], n;
int binary(int a[], int val);

int main()
{
    int choice = 0, val = 0, i, pos;
    char op = 'y';

    printf("Enter the number of elements: \t ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Enter the value: \t");
        scanf("%d", &a[i]);
    }

    while (op != 'n')
    {
        printf("\n Enter the value to be searched: \t");
        scanf("%d", &val);

        pos = binary(a, val);

        if (pos == -1)
        {
            printf("Value not found \n");
        }
        else
        {
            printf("Value found ar position %d \n", (pos+1));
            printf("Continue ?");
            scanf(" %c", &op);
        }
    }

    return 0;
}

int binary(int a[], int val)
{
    int beg=0, end=n-1, mid, found=0;

    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (val == a[mid])
        {
            found = 1;
            return mid;
        }
        else if (val < a[mid])
        {
            end = mid - 1;
        }
        else if (val > a[mid])
        {
            beg = mid + 1;
        }
    }
    if (found == 0 && beg > end)
    {
        return -1;
    }

}

// Output:-

/*
$ ./6-3
Enter the number of elements:    2
Enter the value:        1
Enter the value:        2

 Enter the value to be searched:        2
Value found ar position 2
Continue ?y

 Enter the value to be searched:        4
Value not found

 Enter the value to be searched:        1
Value found ar position 1
Continue ?n
*/