// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to implement Tower of Hanoi problem
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

void move(int n, char source, char dest, char spare);

int main()
{
    int n;

    printf("Enter the number of rings: ");
    scanf("%d", &n);

    move(n, 'A', 'C', 'B');

    return 0;
}

void move(int n, char source, char dest, char spare)
{
    if (n==1)
    {
        printf("\n Move from %c to %c", source, dest);
    }
    else
    {
        move(n-1, source, spare, dest);
        move(1, source, dest, spare);
        move(n-1, spare, dest, source);
    }
}

// Output of the following code

/*
Enter the number of rings: 3

 Move from A to C
 Move from A to B
 Move from C to B
 Move from A to C
 Move from B to A
 Move from B to C
 Move from A to C
 */

// Reference tower of hanoi game: 
// https://www.mathsisfun.com/games/towerofhanoi.html

// This Recursion is most complex I don't even understood the half of it.
// Take a look at this website to visualize things much better
// https://pythontutor.com/

//                  move(3, A, C, B)
//                 /        |                \
//     move(2, A, B, C)   move(1, A, C, B)  move(2, B, C, A)
//         /     |     \                    /       |         \
// move(1, A, C, B)   move(1, A, B, C) move(1, B, A, C) move(1, B, C, A)

