// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to create double linked list and sort the elements in the linked list.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;
struct node *create(struct node*);
struct node *display(struct node*);
struct node *sort(struct node*);

int main()
{
    int opt;

    do
    {
        printf("\n ***** MAIN MENU ***** \n");
        printf("1. Create a list \n");
        printf("2. Display the list \n");
        printf("3. Sort the list \n");
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
            start = sort(start);
            break;

            case 4:
            break;
        }
    } while(opt != 4);
    return 0;
}

struct node *create(struct node *start)
{
    struct node *new_node = NULL, *temp = NULL, *pre;
    int val;

    printf("Enter the data or -1 to exit: ");
    scanf("%d", &val);

    while (val != -1)
    {
        new_node = (struct node*) malloc(sizeof(struct node));
        new_node -> data = val;

        if (start == NULL)
        {
            start = new_node;
            new_node -> next = NULL;
            new_node -> prev = NULL;
        }
        else
        {
            temp = start;

            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }

            temp -> next = new_node;
            new_node -> prev = temp;
            new_node -> next = NULL;
        }

        printf("Enter the data or enter -1 to exit: ");
        scanf("%d", &val);
    }
    printf("Linked list created successfully");
    return start;
}

struct node *display(struct node *start)
{
    struct node *temp = NULL;
    temp = start;

    printf("The Linked list is: ");

    while (temp -> next != NULL)
    {
        printf("%d <--> ", temp -> data);
        temp = temp -> next;
    }

    if (temp -> next == NULL)
    {
        printf("%d \n", temp -> data);
    }

    printf("\n");

    return start;
}

struct node *sort(struct node *start)
{
    struct node *temp1 = start;
    struct node *temp2, *temp;
    int x;

    while (temp1 -> next != NULL)
    {
        temp2 = start;

        while (temp2 -> next != NULL)
        {
            temp = temp2 -> next;

            if (temp2 -> data > temp -> data)
            {
                x = temp -> data;
                temp -> data = temp2 -> data;
                temp2 -> data = x;
            }

            temp2 = temp2 -> next;
        }

        temp1 = temp1 -> next;
    }

    temp = start;

    printf("The linked list is: ");

    while (temp -> next!=NULL)
    {
        printf("%d <--> ", temp -> data);
        temp = temp -> next;
    }

    if (temp -> next == NULL)
    {
        printf("%d \n", temp -> data);
    }

    printf("\n");
    
    return start;
}