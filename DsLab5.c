#include <stdio.h>
#include <stdlib.h>
FILE *fptr; //declaration of file pointer
FILE *fp;
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void push(int val)
{
    struct node *newNode = malloc(sizeof(struct node)); //allocate the memory for a new node
    newNode->data = val;
    newNode->next = NULL;

    //if it is the first node
    if (front == NULL && rear == NULL)
        //make both front and rear points to the new node
        front = rear = newNode;
    else
    {
        //add newnode in rear->next
        rear->next = newNode;

        //make the new node as the rear node
        rear = newNode;
    }
}

void pop()
{
    //used to free the first node after dequeue
    struct node *temp;

    if (front == NULL)
        printf("Queue is Empty. Unable to perform dequeue\n");
    else
    {
        //take backup
        temp = front;

        //make the front node points to the next node
        //logically removing the front element
        front = front->next;
        printf("%d is popped", front->data);

        //if front == NULL, set rear = NULL
        if (front == NULL)
            rear = NULL;

        //free the first node
        free(temp);
    }
}
void search(int n)
{
    struct node *p;
    p = front;
    int count = 0;
    int flag = 1;
    while (p != NULL)
    {
        count++;
        if (p->data == n)
        {
            printf("%d is found at location %d :\n", p->data, count);
            flag = 0;
            break;
        }
        p = p->next;
    }
    if (flag)
    {
        printf("not found\n");
    }
}
void display()
{
    struct node *temp = front;

    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{

    int i, ch, n, x;
    while (1)
    { //MENU
        printf("\nEnter 1 for push: \nEnter 2 for pop: \nEnter 3 for search: \nEnter 4 for display: \nEnter 5 for exit:\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            fptr = fopen("push_queue.txt", "r"); //open the file push_queue to read
            fp = fopen("push_output.txt", "w");

            for (i = 0; i < 7; i++)
            {

                fscanf(fptr, "%d\n", &x); //take the input fromt he file push_queue
                push(x);                  //push function call
                printf("%d is pushed successfully\n", x);
                fprintf(fp, "%d is pushed successfully\n", x);
            }

            fclose(fptr); //closing the file pointer
            fclose(fp);
            printf("\n");

            break;
        case 2:

            pop(); //delete the front element

            break;
        case 3:
            fptr = fopen("search_queue.txt", "r");
            fp = fopen("search_output.txt", "r");
            fscanf(fptr, "%d\n", &n);
            search(n); //search a particular element
            fprintf(fp, "%d is found\n ", n);
            fclose(fptr);
            fclose(fp);
            break;
        case 4:
            display(); //display queue elements
            break;

        case 5:
            exit(0);
        default:
            printf("Invalid choice"); //if user enters the choice other than 1 to 5
        }
    }

    return 0;
}