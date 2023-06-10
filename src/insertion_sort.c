#include <stdlib.h>
#include <stdio.h>

void insertion_sort_ascending(int a[], int len);
void insertion_sort_descending(int a[], int len);
void test_ascending();
void test_descending();
void print_array(int a[], int len);

int main()
{
    test_ascending();
    test_descending();
    return 0;
}

void insertion_sort_ascending(int a[], int len)
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

void insertion_sort_descending(int a[], int len)
{
    int i, j, key;

    for (j = 1; j < len; j++)
    {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] < key)
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}

void test_ascending()
{
    const int len = 5;
    int a[5] = {5, 4, 3, 2, 1};

    int correct[5] = {1, 2, 3, 4, 5};

    insertion_sort_ascending(a, 5);

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

    printf("Insertion sort success\n");
}

void test_descending()
{
    const int len = 5;
    int a[5] = {1, 2, 3, 4, 5};

    int correct[5] = {5, 4, 3, 2, 1};

    insertion_sort_descending(a, 5);

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

    printf("Insertion sort success\n");
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