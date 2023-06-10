#include <stdio.h>
#include <stdlib.h>

void test();
void binary_addition(int a[], int b[], int c[], int len);
void print_array(int a[], int len);

int main()
{
    test();
    return 0;
}

void binary_addition(int a[], int b[], int c[], int len)
{
    int carry = 0;

    for (int j = len - 1; j >= 0; j--)
    {
        int sum = a[j] + b[j] + carry;
        carry = 0;
        if (sum == 0 || sum == 1)
        {
            c[j + 1] = sum;
        }
        else if (sum == 2)
        {
            c[j + 1] = 0;
            carry = 1;
        }
        else if (sum == 3)
        {
            c[j + 1] = 1;
            carry = 1;
        }
    }

    c[0] = carry;
}

void test()
{
    int a[3] = {1, 0, 1}; // 5
    int b[3] = {0, 1, 0}; // 2

    int c[4] = {0, 0, 0, 0};

    int correct[4] = {0, 1, 1, 1};

    binary_addition(a, b, c, 3);

    for (int i = 0; i < 4; i++)
    {
        if (c[i] != correct[i])
        {
            printf("Binarry addition failed\n");
            exit(1);
        }
    }

    printf("Binary addition success\n");
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