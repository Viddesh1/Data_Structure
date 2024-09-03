// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to search the elements in the linked list and display the same.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create(struct node*);
struct node *display(struct node*);
struct node *searchall(struct node*);

int main()
{
    int opt;

    do
    {
        printf("\n ***** MAIN MENU ***** \n");
        printf("1. Create a list \n");
        printf("2. Display the list \n");
        printf("3. search \n");
        printf("4. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
            start = create(start);
            break;

            case 2:
            start = display(start);
            break;

            case 3:
            start = searchall(start);
            break;

            case 4:
            break;
        }
    } while (opt != 4);

    return 0;
}

struct node *searchall(struct node *start)
{
    int val, count = 1, x = 0;
    struct node *temp;

    printf("Which value are you looking for? : \n");
    scanf("%d", &val);

    temp = start;

    while (temp -> data != val && temp -> data != 0x0)
    {
        temp = temp -> next;
        count = count + 1;
    }

    if (temp -> next == NULL && temp -> data != val)
    {
        printf("Value not found in linked list");
    }

    else if (temp -> next == NULL && temp -> data == val)
    {
        printf("Value found at %d node", count);
    }
    else
    {
        printf("Value founf at %d node", count);
    }
    
    return start;
}

struct node *create(struct node *start)
{
    struct node *new_node = NULL , *temp = NULL;
    int val;

    printf("Enter the data or enter -1 to exit: ");
    scanf("%d", &val);

    while (val != -1)
    {
        new_node = (struct node*) malloc(sizeof(struct node));
        new_node -> data = val;

        if (start == NULL)
        {
            start = new_node;
            new_node -> next = NULL;
        }
        else
        {
            temp = start;

            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = new_node;
            new_node -> next = NULL;
        }
        printf("Enter the data or enter -1 to exit: ");
        scanf("%d", &val);
    }
    printf("Linked list successfully created. \n");
    return start;
}

struct node *display(struct node *start)
{
    struct node *temp = NULL;
    temp = start;

    printf("The linked list is: ");
    while (temp != NULL)
    {
        printf("\t %d", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
    return start;
}