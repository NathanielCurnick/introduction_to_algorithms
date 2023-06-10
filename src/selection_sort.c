#include <stdlib.h>
#include <stdio.h>

void selection_sort(int a[], int len);
void test();
void print_array(int a[], int len);

int main()
{
    test();
    return 0;
}

void test()
{
    int a[6] = {6, 5, 4, 3, 2, 1};
    int correct[6] = {1, 2, 3, 4, 5, 6};

    selection_sort(a, 6);

    for (int i = 0; i < 6; i++)
    {
        if (a[i] != correct[i])
        {
            printf("Selection sort failed\n");
            exit(1);
        }
    }

    printf("Selection sort successful\n");
}

void selection_sort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int key = a[i];
        int smallest = key;
        int k = i;

        for (int j = i; j < len; j++)
        {
            if (a[j] < smallest)
            {
                smallest = a[j];
                k = j;
            }
        }

        a[i] = a[k];
        a[k] = key;
    }
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