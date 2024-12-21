// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to insert the element in the maximum heap. (Not perfect though)
// ------------------------------------------------------------------------------------------------------------------------------------


#include <stdio.h>
#define SIZE 30

int a[SIZE], n;

void maxheapify(int a[], int i, int n1);
void buildheap(int a[], int n1);
void swap(int a[], int i, int j);

int main()
{
    int i, j;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter a value: ");
        scanf("%d", &a[i]);
    }

    buildheap(a, n);

    printf("Heapified array: ");
    for (j = 0; j < n; j++)
    {
        printf("%d ", a[j]);
    }
    printf("\n");

    return 0;
}

void buildheap(int a[], int n1)
{
    int i;
    for (i = (n1 / 2) - 1; i >= 0; i--)
    {
        maxheapify(a, i, n1);
    }
}

void maxheapify(int a[], int i, int n1)
{
    int max, l, r;
    max = i;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < n1 && a[l] > a[max])
    {
        max = l;
    }

    if (r < n1 && a[r] > a[max])
    {
        max = r;
    }

    if (i != max)
    {
        swap(a, i, max);
        maxheapify(a, max, n1);
    }
}

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Output
/*
Enter the number of elements: 5
Enter a value: 3
Enter a value: 6
Enter a value: 10
Enter a value: 12
Enter a value: 15
Heapified array: 15 12 10 3 6
*/
