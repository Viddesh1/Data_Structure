// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to create a single linked list and display the node elements in reverse order.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include  <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create(struct node*);
struct node *display(struct node*);
void reverse(struct node*);
struct node *deleteall(struct node*); // Function declare but not used.

int main()
{
    int opt;

    do
    {
        printf("\n ***** MAIN MENU ***** \n");
        printf("1. Create a list \n");
        printf("2. Display list \n");
        printf("3. Reverse \n");
        printf("4. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &opt);

        printf("\n");

        switch(opt)
        {
            case 1: 
            start = create(start);
            break;

            case 2:
            start = display(start);
            break;

            case 3:
            reverse(start);
            break;

            case 4:
            break;
        }
    } while (opt != 4);
}

void reverse(struct node *head)
{
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    head = display(head);
}

struct node *create(struct node *start)
{
    struct node *new_node=NULL, *temp = NULL;
    int val;

    printf("Enter the data or enter -1 to exit: ");
    scanf("%d", &val);

    while (val != -1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
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