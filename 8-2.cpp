// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to insert the element in minimum heap.
// ------------------------------------------------------------------------------------------------------------------------------------


#include <stdio.h>
#define SIZE 30

int a[SIZE], n;

void minheapify(int a[], int i, int n1);
void buildheap(int a[], int n1);
void swap(int a[], int i, int j);

int main()
{
    int i, j;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &a[i]);
    }

    buildheap(a, n);

    printf("Minheapify value are: ");
    for (i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void buildheap(int a[], int n1)
{
    int i;

    for (i = (n1/2)-1; i >= 0; i--)
    {
        minheapify(a, i, n1);
    }
}

void minheapify(int a[], int i, int n1)
{
    int min, l, r;
    
    min = i;
    l = 2*i+1;
    r = 2*i+2;

    if (l < n1 && a[l] < a[min])
    {
        min = l;
    }

    if (r < n1 && a[r] < a[min])
    {
        min = r;
    }

    if (i != min)
    {
        swap(a, i, min);
        minheapify(a, min, n1);
    }
}

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// output
/*
$ ./8-2
Enter the number of elements: 5
Enter value: 15
Enter value: 12
Enter value: 10
Enter value: 3
Enter value: 6
Minheapify value are: 3 6 10 12 15
*/