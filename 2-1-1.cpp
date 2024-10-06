// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to create a single linked list and display the node elements in reverse order.
// (Added deleteall function to delete or free the data in a linked-list)
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create(struct node*);
struct node *display(struct node*);
void reverse(struct node**);  // Changed to accept a pointer to start
struct node *deleteall(struct node*); 

int main() {
    int opt;

    do {
        printf("\n ***** MAIN MENU ***** \n");
        printf("1. Create a list \n");
        printf("2. Display list \n");
        printf("3. Reverse \n");
        printf("4. Delete all \n");
        printf("5. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &opt);

        printf("\n");

        switch(opt) {
            case 1: 
                start = create(start);
                break;

            case 2:
                start = display(start);
                break;

            case 3:
                reverse(&start);  // Pass the address of start
                break;

            case 4:
                start = deleteall(start);
                break;

            case 5:
                break;
        }
    } while (opt != 5);  // Change to exit when opt == 5
}

void reverse(struct node **head) {
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;  // Update the global start pointer
    display(*head);  // Display the reversed list
}

struct node *create(struct node *start) {
    struct node *new_node = NULL, *temp = NULL;
    int val;

    printf("Enter the data or enter -1 to exit: ");
    scanf("%d", &val);

    while (val != -1) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = val;
        new_node->next = NULL;

        if (start == NULL) {
            start = new_node;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        printf("Enter the data or enter -1 to exit: ");
        scanf("%d", &val);
    }
    printf("Linked list successfully created. \n");
    return start;
}

struct node *display(struct node *start) {
    struct node *temp = start;

    printf("The linked list is: ");

    while (temp != NULL) {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return start;
}

struct node* deleteall(struct node *head) {
    struct node *current = head;
    struct node *next;

    while (current != NULL) {
        next = current->next; // Store the next node
        printf("Deleting node with data: %d\n", current->data);
        free(current);        // Free the current node
        current = next;       // Move to the next node
    }

    head = NULL; // After deletion, set head to NULL
    return head;
}


// Output of the following code
/*
$ ./2-1-1

 ***** MAIN MENU *****
1. Create a list 
2. Display list
3. Reverse
4. Delete all
5. Exit
Enter your choice: 1

Enter the data or enter -1 to exit: 1
Enter the data or enter -1 to exit: 2
Enter the data or enter -1 to exit: 3
Enter the data or enter -1 to exit: 4
Enter the data or enter -1 to exit: 5
Enter the data or enter -1 to exit: 6
Enter the data or enter -1 to exit: -1
Linked list successfully created. 

 ***** MAIN MENU *****
1. Create a list
2. Display list
3. Reverse
4. Delete all
5. Exit
Enter your choice: 2

The linked list is:     1       2       3       4       5    
6

 ***** MAIN MENU *****
1. Create a list
2. Display list
3. Reverse
4. Delete all
5. Exit
Enter your choice: 3

The linked list is:     6       5       4       3       2    
1

 ***** MAIN MENU *****
1. Create a list
2. Display list
3. Reverse
4. Delete all
5. Exit
Enter your choice: 4

Deleting node with data: 6
Deleting node with data: 5
Deleting node with data: 4
Deleting node with data: 3
Deleting node with data: 2
Deleting node with data: 1

 ***** MAIN MENU *****
1. Create a list
2. Display list
3. Reverse
4. Delete all
5. Exit
Enter your choice: 2

The linked list is:

 ***** MAIN MENU *****
1. Create a list
2. Display list
3. Reverse
4. Delete all
5. Exit
Enter your choice: 5
*/