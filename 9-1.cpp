// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement the collision technique using quadratic probing.
// References :- https://youtu.be/tfXPEgYDQgI?si=obEjuzlbgo3mCYKg
// https://www.geeksforgeeks.org/quadratic-probing-in-hashing/
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#define SIZE 10

// Function to calculate the hash index
int hashFunction(int key) {
    return key % SIZE;
}

// Function to calculate the rehashed index using quadratic probing
int rehashq(int key, int j) {
    return (key + (j * j)) % SIZE;
}

int main() {
    int hash[SIZE]; // Hash table
    int arr[SIZE];  // Array of elements to be inserted
    int key, n, i, j, index;

    // Initialize hash table to -1 (indicating empty slots)
    for (i = 0; i < SIZE; i++) {
        hash[i] = -1;
    }

    printf("Enter the number of elements (max %d): ", SIZE);
    scanf("%d", &n);

    if (n > SIZE) {
        printf("Error: Number of elements exceeds hash table size.\n");
        return 1; // Return non-zero to indicate an error
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insert elements into the hash table
    for (i = 0; i < n; i++) {
        key = arr[i];
        index = hashFunction(key);
        j = 1;

        // Resolve collisions using quadratic probing
        while (hash[index] != -1) {
            index = rehashq(hashFunction(key), j);
            j++;
        }
        hash[index] = key;
    }

    // Display the hash table
    printf("\nThe elements in the hash table are:\n");
    for (i = 0; i < SIZE; i++) {
        if (hash[i] != -1) {
            printf("Position %d: %d\n", i, hash[i]);
        } else {
            printf("Position %d: Empty\n", i);
        }
    }

    return 0; // Return 0 to indicate successful execution
}


/*
Enter the number of elements (max 10): 5
Enter the elements: 23 43 13 27 18

The elements in the hash table are:
Position 0: Empty
Position 1: Empty
Position 2: Empty
Position 3: 23
Position 4: 43
Position 5: Empty
Position 6: Empty
Position 7: 13
Position 8: 27
Position 9: 18

*/

// How does it work?
/*
Enter the number of elements (max 10): 5
Enter the elements: 23 43 13 27 18

-->

We will initialize an hash with -1 at first which will represents the empty values
that are present in the array. Using rehashq() function we can call the hashq() function
if the element is filled.

let the array = [23, 43, 13, 27, 18]
SIZE = 10
Indexing starts from 0 to 9
index   [array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9]]
array = [Empty,     Empty,      Empty,  Empty,       Empty,  Empty,      Empty,  Empty,   Empty,     Empty]

Iteration 1:-
index = (key % SIZE)
index = (23 % 10) = 3 (array[3] = 23)
index   [array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9]]
array = [Empty,     Empty,      Empty,  23,       Empty,  Empty,      Empty,  Empty,   Empty,     Empty]

Iteration 2:-
index = (key % SIZE)
index = (43 % 10) = 3 (Since 3 is already filled there is a collision) X
index = (key + i * i) % 10
index = (43 + 1 * 1) % 10 
index = (43 + 1) % 10
index = 44 % 10 = 4 (4 index is empty let's fill it with key)
index   [array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9]]
array = [Empty,     Empty,      Empty,  23,       43,  Empty,      Empty,  Empty,   Empty,     Empty]

Iteration 3:-
index = (13 % 10) = 3 (collision X)
index = (13 + 1 * 1) % 10
index = 14 % 10 = 4 (collision X)
index = (13 + 2 * 2) % 10
index = (13 + 4) % 10
index = 17 % 10 = 7 (fill array[7] with key 13)
index   [array[0], |array[1], |array[2], |array[3], |array[4], |array[5], |array[6], |array[7], |array[8], |array[9]]
array = [Empty,    |Empty,    |Empty,    |  23,     | 43,      |Empty,    |Empty,    | 13   |Empty,    |Empty]

Iteration 4:-
index = (27 % 10) = 7 (collision X)
index = (27 + 1*1) % 10 
index = (27 + 1) % 10
index = 28 % 10 = 8 (fill it)
index   [array[0], |array[1], |array[2], |array[3], |array[4], |array[5], |array[6], |array[7], |array[8], |array[9]]
array = [Empty,    |Empty,    |Empty,    |  23,     | 43,      |Empty,    |Empty,    | 13       |27,    |Empty]

Iteration 5:
index = (18 % 10) = 8 (collision X)
index = (18 + 1 * 1) % 10 
index = (18 + 1) % 10
index = 19 % 10 = 9 (fill it)
index   [array[0], |array[1], |array[2], |array[3], |array[4], |array[5], |array[6], |array[7], |array[8], |array[9]]
array = [Empty,    |Empty,    |Empty,    |  23,     | 43,      |Empty,    |Empty,    | 13       |27,       |18]


Final Array becomes:-
index   [array[0], |array[1], |array[2], |array[3], |array[4], |array[5], |array[6], |array[7], |array[8], |array[9]]
array = [Empty,    |Empty,    |Empty,    |  23,     | 43,      |Empty,    |Empty,    | 13       |27,       |18]

The elements in the hash table are:
Position 0: Empty
Position 1: Empty
Position 2: Empty
Position 3: 23
Position 4: 43
Position 5: Empty
Position 6: Empty
Position 7: 13
Position 8: 27
Position 9: 18

*/