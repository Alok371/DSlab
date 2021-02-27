#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
  int data;
  struct node *link;
} *top = NULL;

void push(int x)
{
  struct node *temp;
  temp = malloc(sizeof(struct node));
  if (temp == NULL)
  {
    printf("memory not allocated");
  }
  else
  {
    temp->data = x;
    temp->link = top;
    top = temp;
  }
}
void pop()
{
  if (top == NULL)
  {
    printf("stack underflow");
  }
  else
  {
    struct node *temp;
    temp = top;
    printf("%d is poped ", top->data);
    top = top->link;
    free(temp);
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
        printf("%d is found", key);
        break;
      }
      temp = temp->link;
      if (temp == NULL)
        printf("%d is not found", key);
    }
  }
}
void display()
{
  struct node *temp;
  temp = top;
  if (temp == NULL)
  {
    printf("stack is empty");
  }
  else
  {

    while (temp != NULL)
    {
      printf("%d  ", temp->data);
      temp = temp->link;
    }
  }
}
void main()
{
  int ch, key;
  while (1)
  {
    printf("\nEnter 1 for push: \nEnter 2 for pop: \nEnter 3 for search: \nEnter 4 for display: \nEnter 5 for exit: \n  Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter data to push: ");
      int x;
      scanf("%d", &x);
      push(x);
      break;
    case 2:
      pop();
      break;
    case 3:
      printf("Enter a no to search: ");
      scanf("%d", &key);
      search(key);
      break;
    case 4:
      display();
      break;

    case 5:
      exit(0);
    default:
      printf("Invalid choice");
    }
  }
}
