#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Declare linked list node
struct node
{
    int data;
    struct node *link;
} *top = NULL;

void push(int x) // data in the stack insert at the beginning
{
    struct node *temp; // Create a new node temp and allocate memory
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("memory not allocated");
    }
    else
    {
        temp->data = x;   // Initialize data into temp
        temp->link = top; // Put top pointer reference into temp link
        top = temp;       // Make temp as top of Stack
    }
}
void pop()
{
    if (top == NULL) // Check for stack underflow
    {
        printf("stack underflow");
    }
    else
    {
        struct node *temp;
        temp = top; // Top assign into temp
        printf("%d is poped ", top->data);
        top = top->link; // Assign second node to top
        free(temp);      // Release memory of top node
    }
}
void search(int key)
{
    struct node *temp;
    if (top == NULL)
        printf("stack is empty");
    else
    {
        temp = top;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                printf("%d is found ", key);
                break;
            }
            temp = temp->link;
            if (temp == NULL)
                printf("%d is not found", key);
        }
    }
}
// Function to print all the elements of the stack
void display()
{
    struct node *temp;
    temp = top;
    if (temp == NULL) // Check for stack underflow
    {
        printf("stack is empty");
    }
    else
    {

        while (temp != NULL)
        {
            printf("%d  ", temp->data); // Print node data
            temp = temp->link;          // Assign temp link to temp
        }
    }
}
void main()
{
    int ch, key, x;
    while (1)
    { //MENU
        printf("\nEnter 1 for push: \nEnter 2 for pop: \nEnter 3 for search: \nEnter 4 for display: \nEnter 5 for exit:\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data you want to push:\n");
            int x;
            scanf("%d", &x);
            push(x);
            printf("%d is pushed successfully\n", x);
            break;
        case 2:
            pop(); //delete the top element
            break;
        case 3:
            printf("Enter a number to search: ");
            scanf("%d", &key);
            search(key); //search a particular element
            break;
        case 4:
            display(); //display stack elements
            break;

        case 5:
            exit(0); //exit
        default:
            printf("Invalid choice"); //if user enters the choice other than 1 to 5
        }
    }
}
