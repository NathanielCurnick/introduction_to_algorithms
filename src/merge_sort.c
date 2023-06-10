#include <stdio.h>

void merge(int a[], int l, int m, int r);
void merge_sort(int a[], int l, int r);
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
    int arr_size = sizeof(a) / sizeof(a[0]);
    merge_sort(a, 0, arr_size - 1);

    print_array(a, 6);
}

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1];
    int right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = a[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        right[j] = a[m + 1 + j];
    }

    int k = l;
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);

        merge(a, l, m, r);
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