// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to insert the element in minimum heap. 
//
// Note:-
// 1) In min-heap or minimal heap the root element is always minimum then that
// of the child elements.
// The grand child elements of the root should also be minimum then that of child elements. 
// ------------------------------------------------------------------------------------------------------------------------------------


#include <stdio.h>  // Importing the standard input and output
#define SIZE 30     // Limiting the size to 30 as constant.

int a[SIZE], n; // Declaring the global variable as integer to use later.

void minheapify(int a[], int i, int n1);    
void buildheap(int a[], int n1);
void swap(int a[], int i, int j);

int main()
{
    int i;

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
    // Builds the heap 
    int i;

    for (i = (n1/2)-1; i >= 0; i--) // Nice way to get the root of a binary tree from bottom to top.
    {
        // Perform the min check to check which value is less than that to root.
        minheapify(a, i, n1);
    }
}

void minheapify(int a[], int i, int n1)
{
    // Recursively checking from ground up.
    int min, l, r;
    
    min = i;
    l = 2*i+1;  // Nice way to get the left element from the child root ground up.
    r = 2*i+2; // To get the right element from the child root from butom to top root element.

    if (l < n1 && a[l] < a[min]) 
    // Perform checks if the left remote child is lesser then number of elements
    // And
    // check if the left element is greater then current min value.
    // Performing l < n1 is important other wise the min array is exploding to larger value of index
    // has a result gives segmentation fault.
    {
        min = l;    // Gets the minimal index
    }

    if (r < n1 && a[r] < a[min])
    // Gets the minimal index from check right value to number of elements 
    // and
    // if the current min or the min is greater.
    {
        min = r;
    }

    if (i != min) // useful when looping out of recursion.
    {
        swap(a, i, min);
        minheapify(a, min, n1); // Recursive call until i == min --> false
    }
}

void swap(int a[], int i, int j)
{
    // Swap logic

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