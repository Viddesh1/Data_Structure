// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement the concept of linear probing.
// Reference:- https://youtu.be/98Y0UDZ9vvs?si=Iq9R3bwGHdAU_LkE
// Information:-
// Linear probing is a collision resolution technique in hash tables where, upon a collision, the algorithm searches the next 
// available slot sequentially (wrapping around if necessary). 
// It is simple and efficient for low load factors but can suffer from clustering issues as the table fills.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#define SIZE 10

// Function to calculate the hash index
int hashFunction(int key)
{
    return key % SIZE;
}

int main()
{
    int arr[SIZE];  // To store user data as array
    int hash[SIZE]; // hash array 
    int i;          // Iterable
    int index;      // index value = key % SIZE 
    int key;        // key value
    int n;          // User size maximum is 10 (SIZE)

    // Initializing with -1 it represents empty array
    for (i=0; i<SIZE; i++)
    {
        hash[i] = -1;
    }

    printf("Enter the number of elements (max is %d) ", SIZE);
    scanf("%d", &n);

    if (n > SIZE)
    {
        printf("Value cannot be greater than %d. Choose a value lower than %d", SIZE, SIZE);
        return 1;
    }

    if (n < 0)
    {
        printf("Value cannot be negative.");
        return 1;
    }

    for (i=0; i<n; i++)
    {
        printf("Enter %d value: ", i);
        scanf("%d", &arr[i]);
    }

    for (i=0; i<n; i++)
    {
        key = arr[i];
        index = hashFunction(key);

        while (hash[index] != -1)
        {
            index = (index + 1) % SIZE; // Modular arithmetic logic also to do to first element from last element if filled.

        }
        hash[index] = key;
    }

    printf("\n");

    for (i=0; i<n; i++)
    {
        if (hash[i] != -1)
        {
            printf("Hash index %d and value is: %d \n", i, hash[i]);
        }
        else
        {
            printf("Hash index %d is Empty \n", i);
        }
    }

    return 0;
}

// Output:- 
/*
Enter the number of elements (max is 10) 8
Enter 0 value: 25
Enter 1 value: 34
Enter 2 value: 99
Enter 3 value: 54
Enter 4 value: 88
Enter 5 value: 95
Enter 6 value: 47
Enter 7 value: 48

Hash index 0 and value is: 47
Hash index 1 and value is: 48
Hash index 2 is Empty
Hash index 3 is Empty
Hash index 4 and value is: 34
Hash index 5 and value is: 25
Hash index 6 and value is: 54
Hash index 7 and value is: 95
*/
