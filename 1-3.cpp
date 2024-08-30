// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to perform the matrix addition, multiplication and transpose operation. [Menu Driven]
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int a[10][10];  // To get the data of 1st matrix
int b[10][10];  // To get the data of 2nd matrix
int c[10][10];  // Matrix addition
int m;          // Row length of 1st matrix
int n;          // Column length of 1st matrix
int m1;         // Row length of 2nd matrix
int n1;         // Column length of 2nd matrix

void transpose1();
void transpose2();
void create1();
void create2();
void matrixadd();
void multiply();

int main()
{
    int i, j;
    int op, val, choice;

    do
    {
        printf("\n ***** MAIN MENU ***** \n");
        printf("1. Create 1st matrix: \n");
        printf("2. Create 2nd matrix: \n");
        printf("3. Addition \n");
        printf("4. Multiplication \n");
        printf("5. Transpose of 1st matrix: \n");
        printf("6. Transpose of 2nd matrix \n");
        printf("7. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            create1();
            break;

            case 2:
            create2();
            break;

            case 3:
            matrixadd();
            break;

            case 4:
            multiply();
            break;

            case 5:
            transpose1();
            break;

            case 6:
            transpose2();
            break;

            case 7:
            break;
        }
    } while (choice != 7);
}

void create1()
{
    int i, j;

    printf("Enter the number of rows and colums of 1st matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements 1st of matrix: \n");
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The 1st array is: \n");
    for (i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d \t", a[i][j]);
        }
        printf("\n");
    }
}

void create2()
{
    int i, j;

    printf("Enter the number of rows and columns of 2nd matrix: ");
    scanf("%d %d", &m1, &n1);

    printf("Enter the elements of 2nd matrix: \n");
    for (i=0; i<m1; i++)
    {
        for (j=0; j<n1; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("The 2nd matrix is: \n");
    for (i=0; i<m1; i++)
    {
        for (j=0; j<n1; j++)
        {
            printf("%d \t", b[i][j]);
        }
        printf("\n");
    }
}

void matrixadd()
{
    int i, j;

    if (m==m1 && n==n1)
    {
        printf("Sum of the first and second matrix is: \n");
        for (i=0; i<m1; i++)
        {
            for (j=0; j<n1; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
                printf("%d \t", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Order incorrect make sure rows and columns length are same");
    }
}

void multiply()
{
    int i, j, k, result[10][10], sum=0;

    if (n==m1) // If the column length of the first matrix is equal to row length of second matrix
    {
        for (i=0; i<m; i++)
        {
            for (j=0; j<n1; j++)
            {
                for (k=0; k<m1; k++)
                {
                    sum = sum + a[i][k] * b[k][j];
                }
                result[i][j] = sum;
                sum = 0;
            }
        }

        for (i=0; i<m; i++)
        {
            for (j=0; j<n1; j++)
            {
                printf("%d \t", result[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Order incorrect");
    }
}

void transpose1()
{
    int i, j, trans[10][10];

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            trans[j][i] = a[i][j]; 
        }
    }

    for (i=0; i<m; i++)
    {
        for (j=0; j<n1; j++)
        {
            printf("%d \t", trans[i][j]);
        }
        printf("\n");
    }
}

void transpose2()
{
    int i, j, trans[10][10];

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            trans[j][i] = b[i][j];
        }
    }

    for (i=0; i<m; i++)
    {
        for (j=0; j<n1; j++)
        {
            printf("%d \t", trans[i][j]);
        }
        printf("\n");
    }
}