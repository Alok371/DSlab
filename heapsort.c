#include <stdio.h>
  int main()
  {
  int a[10], n,  i, j, c, heap, temp;
  printf("Input number of elements: ");
  scanf("%d", &n);
  printf("\nInput array values one by one : ");
  for (i = 0; i <  n; i++)
  scanf("%d", &a[i]);
  for (i = 1; i <  n; i++)
  {
  c = i;
  do
  {
  heap  = (c - 1) / 2;
  /* to create MAX arr  array */
  if  (a[heap] < a[c])
  {
  temp =  a[heap];
  a[heap] = a[c];
  a[c]  = temp;
  }
  c =  heap;
  } while (c !=  0);
  }
  
  printf("Heap  array : ");
  for (i = 0; i <  n; i++)
  printf("%d\t ", a[i]);
  for (j = n - 1; j  >= 0; j--)
  {
  temp = a[0];
  a[0] = a[j];
  a[j] = temp;
  heap = 0;
  do
  {
  c = 2 *  heap + 1;
  if  ((a[c] < a[c + 1]) && c < j-1)
  c++;
  if  (a[heap]<a[c] && c<j)
  {
  temp =  a[heap];
  a[heap] = a[c];
  a[c]  = temp;
  }
  heap  = c;
  } while (c  < j);
  } 
  printf("\nSorted  array : ");
  for (i = 0; i <  n; i++)
  printf("\t%d", a[i]);
  printf("\n");
  }