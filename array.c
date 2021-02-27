#include <stdio.h>
int main()
{
   int a[100], i, first, last, mid, s, num, choice, pos;

   while (1)
   {

      {
         printf("\nEnter 1 to read & print elements in array:\t");
         printf("\nEnter 2 to insert elements in array:\t");
         printf("\nEnter 3 to Delete elements in array:\t");
         printf("\nEnter 4 to binary searching of an array:\t");
         printf("\nEnter 5 to linear searching in array:\t");
         printf("\nEnter 6 to update elements in array:\t");
         printf("\nEnter 7 to Exit:\t");
         printf("\nEnter the choice:");
         scanf("%d", &choice);
         switch (choice)
         {
         case 1:
            printf("Enter the size of an array:");
            scanf("%d", &s);

            printf("Please Enter %d elements of an Array \n", s);
            for (i = 0; i < s; i++)
            {
               scanf("%d", &a[i]);
            }

            printf("\n Element in this Array are :\n");
            for (i = 0; i < s; i++)
            {
               printf("%d", a[i]);
               printf("\t");
            }
            break;
         case 2:
            printf("Enter size of an array:\n");
            scanf("%d", &s);

            printf("Enter elements of array: \n", s);

            for (i = 0; i < s; i++)
               scanf("%d", &a[i]);

            printf("Enter the position where you want to insert data\n");
            scanf("%d", &pos);

            printf("Enter the data you want to insert:\n");
            scanf("%d", &num);

            for (i = s - 1; i >= pos - 1; i--)
               a[i + 1] = a[i];

            a[pos - 1] = num;

            printf("THe array elements after insertion is:\n");

            for (i = 0; i <= s; i++)
               printf("%d\n", a[i]);
            break;
         case 3:
            printf("Enter the size of an array\n");
            scanf("%d", &s);

            printf("Enter %d elements\n", s);

            for (i = 0; i < s; i++)
               scanf("%d", &a[i]);

            printf("Enter the position you wish to delete element\n");
            scanf("%d", &pos);

            if (pos >= i + 1)
               printf("Deletion not possible.\n");
            else
            {
               for (i = pos - 1; i < s - 1; i++)
                  a[i] = a[i + 1];

               printf("Value of array after deletion are:\n");

               for (i = 0; i < s - 1; i++)
                  printf("%d\n", a[i]);
            }
            break;

         case 4:
            printf("Enter size of an array\n");
            scanf("%d", &s);

            printf("Enter %d integers in sorted form\n", s);

            for (i = 0; i < s; i++)
               scanf("%d", &a[i]);

            printf("Enter the number to search:\n");
            scanf("%d", &num);

            first = 0;
            last = s - 1;
            mid = (first + last) / 2;

            while (first <= last)
            {
               if (a[mid] < num)
                  first = mid + 1;
               else if (a[mid] == num)
               {
                  printf("%d is present at location %d.\n", num, mid + 1);
                  break;
               }
               else
                  last = mid - 1;

               mid = (first + last) / 2;
            }
            if (first > last)
               printf("%d isn't present inthe array.\n", num);
            break;
         case 5:
            printf("Enter size of an array\n");
            scanf("%d", &s);

            printf("Enter %d integers\n", s);

            for (i = 0; i < s; i++)
               scanf("%d", &a[i]);

            printf("Enter a number to search\n");
            scanf("%d", &num);

            for (i = 0; i < s; i++)
            {
               if (a[i] == num)
               {
                  printf("%d is present at location %d.\n", num, i + 1);
                  break;
               }
            }
            if (i == s)
               printf("%d isn't present in the array.\n", num);
            break;
         case 6:
            printf("Enter the size of array:");
            scanf("%d", &s);

            printf("Enter %d elements of array:\n", s);
            for (i = 0; i < s; i++)
            {
               scanf("%d", &a[i]);
            }
            printf("Enter in which position you want to update:\n");
            scanf("%d", &pos);
            printf("Enter the number:");
            scanf("%d", &num);
            a[pos - 1] = num;
            printf("After updation array elements are:\n");
            for (i = 0; i < s; i++)

               printf("%d\t", a[i]);
            break;
         case 7:
            return 0;
         default:
            printf("Invalid Choice!");
         }
      }
   }
}