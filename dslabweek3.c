#include <stdio.h>
void quicksort(int a[100], int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}
int main()
{
    int a[100], n, i, j, temp, choice, c, heap;

    while (1)
    {

        {
            printf("\nEnter 1 for sorting using Quick sort\t");
            printf("\nEnter 2 for sorting using Heap sort\t");
            printf("\nEnter 3 for sorting using Bubble sort\t");
            printf("\nEnter 4 to Exit\t");
            printf("\nEnter your choice:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter number of Elements: ");
                scanf("%d", &n);

                printf("Enter %d elements:\n ", n);
                for (i = 0; i < n; i++)
                    scanf("%d", &a[i]);

                quicksort(a, 0, n - 1);

                printf("Sorted elements are:\n ");
                for (i = 0; i < n; i++)
                    printf(" %d\t", a[i]);
                break;

            case 2:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter %d elements :\n ", n);
                for (i = 0; i < n; i++)
                    scanf("%d", &a[i]);
                for (i = 1; i < n; i++)
                {
                    c = i;
                    do
                    {
                        heap = (c - 1) / 2;

                        if (a[heap] < a[c])
                        {
                            temp = a[heap];
                            a[heap] = a[c];
                            a[c] = temp;
                        }
                        c = heap;
                    } while (c != 0);
                }

                printf("Heap array :\n ");
                for (i = 0; i < n; i++)
                    printf("%d\t ", a[i]);
                for (j = n - 1; j >= 0; j--)
                {
                    temp = a[0];
                    a[0] = a[j];
                    a[j] = temp;
                    heap = 0;
                    do
                    {
                        c = 2 * heap + 1;
                        if ((a[c] < a[c + 1]) && c < j - 1)
                            c++;
                        if (a[heap] < a[c] && c < j)
                        {
                            temp = a[heap];
                            a[heap] = a[c];
                            a[c] = temp;
                        }
                        heap = c;
                    } while (c < j);
                }
                printf("\nSorted  array :\n ");
                for (i = 0; i < n; i++)
                    printf("%d\t", a[i]);
                printf("\n");

                break;

            case 3:
                printf("Enter number of elements\n");
                scanf("%d", &n);

                printf("Enter %d elements:\n", n);

                for (i = 0; i < n; i++)
                    scanf("%d", &a[i]);

                for (i = 0; i < n - 1; i++)
                {
                    for (j = 0; j < n - i - 1; j++)
                    {
                        if (a[j] > a[j + 1])
                        {
                            temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                    }
                }

                printf("Sorted elements are:\n");

                for (i = 0; i < n; i++)
                {
                    printf("%d\t", a[i]);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice!");
            }
        }
    }
}