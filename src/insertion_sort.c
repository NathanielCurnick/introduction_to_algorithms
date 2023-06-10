#include <stdlib.h>
#include <stdio.h>

void insertion_sort(int a[], int len);
void test();
void print_array(int a[], int len);

int main()
{
    test();
    return 0;
}

void insertion_sort(int a[], int len)
{

    int i, j, key;

    for (j = 1; j < len; j++)
    {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}

void test()
{
    const int len = 5;
    int a[5] = {5, 4, 3, 2, 1};

    int correct[5] = {1, 2, 3, 4, 5};

    insertion_sort(a, 5);

    for (int i = 0; i < len; i++)
    {
        if (a[i] != correct[i])
        {
            printf("Insertion sort was a failure\n");
            printf("Correct: ");
            print_array(correct, len);
            printf("\n");
            printf("Algorithm:");
            print_array(a, len);
            printf("\n");

            exit(1);
        }
    }

    printf("Insertion sort success");
}

void print_array(int a[], int len)
{
    printf("[");
    for (int i = 0; i < len; i++)
    {
        printf(" %d", a[i]);
    }

    printf(" ]");
}