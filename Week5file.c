#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
  struct node
  {
  	int data;
  	struct node *next;
  };
  struct node *front=NULL;
  struct node *rear=NULL;
  struct node *newnode,*temp;
  main()
  {
 	while(1)
 	{
 		int choice;
 		char ch;
 		printf("******************************************************************************\n");
 		printf("1.Enqueue Operation\n2.Dequeue Operation\n3.Peek Operation\n4.Search Operation\n5.Printing Operation\n6.Exit\n");
 		printf("Enter your choice:");
 		scanf("%d",&choice);
 		switch(choice)
 		{
 		 case 1:
		   Enqueue();
		   break;
		 case 2:
		   Dequeue();
		   break;
		 case 3:
		   Peek();
		   break;
		 case 4:
		   Search();
		   break;
		 case 5:
		   Printing();
		   break;
		 case 6:
		  	exit(0);
		 default:
		  	 printf("Invalid operation:Please Enter Any charecter to choose for correct choice:\n");
		}
 		ch=getch();
 	}
  }
  
  
  Enqueue()
  {
  	  FILE *fptr;
  	  fptr=fopen("f:\\enqueue.txt","a");
  	  if(fptr==NULL)
  	{
  	  printf("Unable to open a file:\n");
  	  return 0;
    }
  	  else
  	   newnode=(struct node *)malloc(sizeof(struct node));
  	   printf("Enter a data:");
  	   scanf("%d",&newnode->data);
  	   newnode->next=NULL;
  	  if(front==NULL && rear==NULL)
  		front=rear=newnode;
  	 else
  	 {
  	 	rear->next=newnode;
  	 	rear=newnode;
  	 }
  	 printf("%d is Enqueued:\n",newnode->data);
  	 fprintf(fptr,"%d is Enqued\n",newnode->data);
  	 fclose(fptr);
  }
  
  
  Dequeue()
  {
  	 FILE *fptr;
  	  fptr=fopen("f:\\Dequeue.txt","a");
  	  if(fptr==NULL)
  	{
  	  printf("Unable to open a file:\n");
  	  return 0;
    }
    if(front==NULL&&rear==NULL)
   {
    printf("Queue is underflow:");
    fprintf(fptr,"%s","Queue is underflow");
   }
   else
   {
    temp=front;
    front=front->next;
    printf("Dequeued Item=%d\n",temp->data);
    fprintf(fptr,"Dequeued item=%d\n",temp->data);
    free(temp);
      fclose(fptr);
  }
}



  Search()
  {
      FILE *fptr;
      int n;
  	  fptr=fopen("f:\\Search.txt","a");
  	  if(fptr==NULL)
  	{
  	  printf("Unable to open a file:\n");
  	  return 0;
    }	
  	 if(front==NULL&&rear==NULL)
  	 {
  	  printf("Queue is underflow:");
     }
  	 else
  	  printf("Enter a data which you want to search:");
  	  scanf("%d",&n);
  	  temp=front;
  	 	while(temp!=NULL)
  		{
  			if(temp->data==n)
  			{
  		     printf("Searching sucessful:\n");
  		     fprintf(fptr,"%s","Searching Sucessful:\n");
  		     //fprintf(fptr,"Searched Item=%d is sucessfull:\n",n);
  		      break;
			}
  		    temp=temp->next;
  		    //exit(0);
  		   
  		    
  		}
  		if(temp==NULL)
  		{
  		  printf("Data not found::\n");
  		  fprintf(fptr,"%d is not prasent in the queue:\n",n);
  		  fclose(fptr);
  	    }
   }
  
   
  Peek()
  {
  	FILE *fptr;
  	  fptr=fopen("f:\\Top.txt","a");
  	  if(fptr==NULL)
  	{
  	  printf("Unable to open a file:\n");
  	  return 0;
    }
    if(front==NULL&&rear==NULL)
  	printf("Queue is underflow:\n");
  	else
  	printf("top=%d",front->data);
  	fprintf(fptr,"Top=%d\n",front->data);
  	//printf("\n");
  	fclose(fptr);
  }
  
  
  Printing()
  {
      FILE *fptr;
  	  fptr=fopen("f:\\Print.txt","a");
  	  if(fptr==NULL)
  	{
  	  printf("Unable to open a file:\n");
  	  return 0;
    }
  	 if(front==NULL && rear==NULL)
  	   printf("Queue is underflow:");
  	 else
  	 {
  		temp=front;
  		while(temp!=NULL)
  		{
  			printf("%d ",temp->data);
  			fprintf(fptr,"%d\n",temp->data);
  			temp=temp->next;
  		}
  			printf("\n");
  		 	fclose(fptr);
  	}
 
  }
  
  
  
  
  
