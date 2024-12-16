// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to create the tree and display the elements
// Write a program to construct the binary tree.
// Write a program to perform inorder, preorder and postorder traversal.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
struct node *create(struct node*);
struct node *display(struct node*);

void preorder(struct node *temp);
void postorder(struct node *temp);
void inorder(struct node *temp);

int main()
{
    int choice, val, count, min, max;

    do
    {
        printf("***** MAIN MENU ***** \n");
        printf("1. Create a binary search tree \n");
        printf("2. Display the binary search tree \n");
        printf("3. Exit \n \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n\n");

        switch (choice)
        {
            case 1: 
            root = create(root);
            break;

            case 2:
            root = display(root);
            break;

            case 3:
            break;
        }

    } while (choice != 3);
    
    return 0;
}

struct node *create(struct node *root)
{
    struct node *newnode = NULL, *temp = NULL, *parent = NULL;
    int val;

    printf("Enter the data or enter -1 to exit: ");
    scanf("%d", &val);

    while (val != -1)
    {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode -> data = val;

        if (root == NULL)
        {
            root = newnode;
            newnode -> left = NULL;
            newnode -> right = NULL;
        }
        else
        {
            temp = root;

            while (temp != NULL)
            {
                parent = temp;

                if (val < temp -> data)
                {
                    temp = temp -> left;
                }
                else
                {
                    temp = temp -> right;
                }
            }

            if (val < parent -> data)
            {
                parent -> left = newnode;
                newnode -> left = NULL;
                newnode -> right = NULL;
            }
            else
            {
                parent -> right = newnode;
                newnode -> left = NULL;
                newnode -> right = NULL;
            }
        }
    
        printf("Enter the data or enter -1 to exit: ");
        scanf("%d", &val);
    }
    printf("Successfully created \n \n");
    return root;
}

struct node *display(struct node *root)
{
    int choice1;

    printf("\t ----- Display Menu ----- \n");
    printf("\t 1. pre-order \n");
    printf("\t 2. In-order \n");
    printf("\t 3. Post-order \n");
    printf("\t 4. Exit \n");

    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch(choice1)
    {
        case 1:
        printf("\t The pre-order traversal is: ");
        preorder(root);
        break;

        case 2:
        printf("In-order traversal is : ");
        inorder(root);
        break;

        case 3:
        printf("post-order traversal is : ");
        postorder(root);
        break;

        case 4:
        break;

    }
    printf("\n");
    return root;
}

void preorder(struct node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp -> data);
        preorder(temp -> left);
        preorder(temp -> right);
    }
}
void postorder(struct node *temp)
{
    if (temp != NULL)
    {
        postorder(temp -> left);
        postorder(temp -> right);
        printf("%d ", temp -> data);
    }
}

void inorder(struct node *temp)
{
    if (temp != NULL)
    {
        inorder(temp -> left);
        printf("%d ", temp -> data);
        inorder(temp -> right);
    }
}

//Output
/*
***** MAIN MENU *****
1. Create a binary search tree
2. Display the binary search tree
3. Exit

Enter your choice: 1


Enter the data or enter -1 to exit: 34
Enter the data or enter -1 to exit: 5
Enter the data or enter -1 to exit: 6
Enter the data or enter -1 to exit: 2
Enter the data or enter -1 to exit: 1
Enter the data or enter -1 to exit: -1
Successfully created 

***** MAIN MENU *****
1. Create a binary search tree
2. Display the binary search tree
3. Exit

Enter your choice: 2


         ----- Display Menu -----
         1. pre-order
         2. In-order
         3. Post-order
         4. Exit
Enter your choice: 1
         The pre-order traversal is: 34 5 2 1 6 
***** MAIN MENU *****
1. Create a binary search tree
2. Display the binary search tree
3. Exit

Enter your choice: 2


         ----- Display Menu -----
         1. pre-order
         2. In-order
         3. Post-order
         4. Exit
Enter your choice: 2
In-order traversal is : 1 2 5 6 34
***** MAIN MENU *****
1. Create a binary search tree
2. Display the binary search tree
3. Exit

Enter your choice: 2


         ----- Display Menu -----
         1. pre-order
         2. In-order
         3. Post-order
         4. Exit
Enter your choice: 3
post-order traversal is : 1 2 6 5 34
***** MAIN MENU *****
1. Create a binary search tree
2. Display the binary search tree
3. Exit

Enter your choice: 3
*/