#include <stdio.h>
#define s 10
int *input_array(int *array, int *length)
{
    int i, a, k = 0;
    for (i = 0; i < s; i++)
    {
        printf("Enter your number: ");
        scanf("%d", &a);
        if (a < 0)
            break;
        *(array + i) = a;
        k = k + 1;
    }
    length = &k;
    return length;
}

int reverse_array(int *array, int *length)
{
    int i, n, j;
    n = *length / 2;
    for (i = 0; i < n; i++)
    {
        j = *(array + i);
        *(array + i) = *(array + (*length) - 1 - i);
        *(array + (*length) - 1 - i) = j;
    }
    // return &array[0];
}

int *check_unique_array(int *array, int *length)
{
    int i, n, j, var, *binary;
    n = *length;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (*(array + i) == *(array + j))
                var = 1;
        }
    }
    binary = &var;
    return binary;
}

int main()
{
    int *length, array[s], *base, *unique, i;

    printf("Max size of an array = 100\n");
    length = input_array(array, length);
    printf("Length of array = %d\n", *length);
    printf("Entered input is:");
    for (i = 0; i < *length; i++)
    {
        printf("\t%d", *(array + i));
    }

    // base =
    reverse_array(array, length);
    printf("\nReversed input is:");
    for (i = 0; i < *length; i++)
    {
        printf("\t%d", *(array + i));
    }

    unique = check_unique_array(array, length);
    if (*unique == 1)
        printf("\nArray elements are not unique.");
    else
        printf("\nArray elements are unique.");
    return 0;
}
