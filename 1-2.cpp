// ------------------------------------------------------------------------------------------------------------------------------------
// Read the two arrays from the user and merge them and display the elements in sorted order. [Menu Driven]
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int arr1[20], arr2[20], arr[40];
int n;

void disp(int arr[]);
void create(int arr[]);
void bubblesort(int temp[]);
void merged(int l[], int r[]);
int length(int temp[]);

int main()
{
    int i;
    int opt, val, choice;

    do
    {
        printf("\n ***** MAIN MENU ***** \n");
        printf("1. Create 1st array: \n");
        printf("2. Create 2nd array: \n");
        printf("3. Sort 1st array \n");
        printf("4. Sort 2nd array \n");
        printf("5. Merge \n");
        printf("6. Sorted Merged array \n");
        printf("7. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
            create(arr1);
            printf("1st array is: ");
            disp(arr1);
            break;

            case 2: 
            create(arr2);
            printf("2nd array is: ");
            disp(arr2);
            break;

            case 3: 
            bubblesort(arr1);
            printf("Sorted 1st array is: ");
            disp(arr1);
            break;

            case 4: 
            bubblesort(arr2);
            printf("Sorted 2nd array is: ");
            disp(arr2);    
            break; 

            case 5: 
            merged(arr1, arr2);
            break;

            case 6:
            printf("The merged sorted array is: ");
            disp(arr);
            break;

            case 7:
            break;
        }
    }while(choice != 7);
}

void create(int temp[])
{
    int i, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &temp[i]);
    }
}


int length(int temp[])
{
    int i = 0;

    while (temp[i] != 0)
    {
        i++;
    }
    return i;
}

void disp(int temp[])
{
    int i;
    n = length(temp);

    for (i=0; i<n; i++)
    {
        printf("%d\n", temp[i]);
    }
}

void bubblesort(int temp[])
{
    int i, j, x;
    n = length(temp);

    for (i=0; i<n; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if (temp[j] > temp[j+1])
            {
                x = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = x;
            }
        }
    }
}

void merged(int l[], int r[])
{
    int n1, n2;
    int i=0, j=0, k=0;

    n1 = length(l);
    n2 = length(r);

    while (i<n1 && j<n2)
    {
        if (l[i] < r[j])
        {
            arr[k] = l[i];

            i++;
            k++;
        }
        else
        {
            arr[k] = r[j];
            
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = l[i];

        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = r[j];

        j++;
        k++;
    }
}


// Output of the following code
/*
$ ./1-2

 ***** MAIN MENU *****
1. Create 1st array: 
2. Create 2nd array:
3. Sort 1st array
4. Sort 2nd array
5. Merge
6. Sorted Merged array
Enter your choice: 1
Enter number of elements: 5
Enter 0th element5
Enter 1th element4
Enter 2th element3
Enter 3th element2
Enter 4th element1
1st array is: 5
4
3
2
1

 ***** MAIN MENU *****
1. Create 1st array:
2. Create 2nd array:
3. Sort 1st array
4. Sort 2nd array
5. Merge
6. Sorted Merged array
Enter your choice: 2
Enter number of elements: 5 
Enter 0th element10
Enter 1th element9
Enter 2th element8
Enter 3th element7
Enter 4th element6
2nd array is: 10
9
8
7
6

 ***** MAIN MENU *****
1. Create 1st array:
2. Create 2nd array:
3. Sort 1st array
4. Sort 2nd array
5. Merge
6. Sorted Merged array
Enter your choice: 3
Sorted 1st array is: 1
2
3
4
5

 ***** MAIN MENU *****
1. Create 1st array:
2. Create 2nd array:
3. Sort 1st array
4. Sort 2nd array
5. Merge
6. Sorted Merged array
Enter your choice: 4
Sorted 2nd array is: 6
7
8
9
10

 ***** MAIN MENU *****
1. Create 1st array:
2. Create 2nd array:
3. Sort 1st array
4. Sort 2nd array
5. Merge
6. Sorted Merged array
Enter your choice: 5

 ***** MAIN MENU *****
1. Create 1st array:
2. Create 2nd array:
3. Sort 1st array
4. Sort 2nd array
5. Merge
6. Sorted Merged array
Enter your choice: 6
The merged sorted array is: 1
2
3
4
5
6
7
8
9
10

 ***** MAIN MENU *****
1. Create 1st array:
2. Create 2nd array:
3. Sort 1st array
4. Sort 2nd array
5. Merge
6. Sorted Merged array
Enter your choice: 7
*/