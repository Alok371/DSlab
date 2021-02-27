#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void Enqueue(int val);
void Dequeue();
void Display();
void Search(int data);

FILE *fptr;
struct node
{

    int val;
    struct node *next;

} *front = NULL, *rear = NULL;

int main()
{
    int choice, i;
    int data, val;
    while (1)
    { //MENU
        printf("\nChoose any one from the below options:\n");
        printf("\n1.Enqueue:\n2.Dequeue:\n3.Search for an element in a Queue:\n4.Display elements\n5.Exit");
        printf("\nEnter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int n;
            fptr = fopen("queue_input.txt", "r"); // open the file in read mode to take input
            printf("Enter how many element you want to insert:");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                fscanf(fptr, "%d", &val); //takes the inputs from the file
                Enqueue(val);             //enqueue function call
            }
            fclose(fptr); //closing the file
            break;
        }
        case 2:
        {
            Dequeue(); //dequeue function call
            break;
        }
        case 3:
        {
            if (front == NULL) //check whether front is empty or not
                printf("\n Queue is Empty!!! \n");
            else
            {
                printf("Enter the value to search:\n");
                scanf("%d", &data);
                Search(data); //search function call
            }
            break;
        }
        case 4:
        {
            fopen("queue_output.txt", "w"); //opens the file in write mode
            Display();                      //display function call
            fclose(fptr);
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
        {
            printf("Please Enter valid choice!! ");
        }
        };
    }

    return 0;
}

void Enqueue(int val)
{
    struct node *temp;                                 
    temp = (struct node *)malloc(sizeof(struct node)); //allocate the memory for a new node
    //create a newnode with given value
    temp->val = val;
    temp->next = NULL;
    if (front == NULL)
        front = rear = temp;

    else //inserting newnode if list is not empty
    {
        rear->next = temp; // Make the new node as REAR
        rear = temp;
    }
    printf("\n %d is Inserted Successfully \n", temp->val);
}

void Dequeue()
{
    if (front == NULL) //check whether queue is empty or not
        printf("\n Queue is Empty!!! \n");
    else
    {
        struct node *temp = front; // define a Node pointer 'temp' and set it to 'front'
                                   // then Move FRONT to the next node 
        front = front->next;       
        printf("\nDeleted element: %d\n", temp->val);
        free(temp);// Delete the temporary node
    }
}

void Search(int data) //Function to display elements
{
    struct node *temp = front;
    int count = 0;
    while (temp != NULL) //check whether the address part of a node is null
    {
        count++;
        if (temp->val == data) //if we get the desire data in the queue it will print its loctaion
        {
            printf("Element is fount at index %d", count);
            return;
        }
        temp = temp->next; //if we dont found then 
    }
    printf("Element is not present in Queue.\n");
}

void Display()
{
    if (front == NULL) // Check whether queue is Empty or not
    {
        fprintf(fptr, "Queue is Empty!!!");
        printf("\n Queue is Empty!!! \n");
    }
    else
    {
        struct node *temp = front; //define a Node pointer 'temp' and initialize with front
        fprintf(fptr, "Elements in the queue are: "); //displaying it in output file
        while (temp != NULL)
        {
            printf("%d ", temp->val); //Display 'temp → val'
            fprintf(fptr, "%d ", temp->val);
            temp = temp->next; //move temp to the next node.
        } //Repeat the same until 'temp' reaches to 'rear'
    }
}