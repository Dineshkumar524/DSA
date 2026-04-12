#include <stdio.h>
#define s 100

int* input_array(int *array, int *length)
{
    int i = 0, x;

    printf("Enter elements (negative to stop):\n");

    while(i < s)
    {
        scanf("%d", &x);
        if(x < 0)
            break;

        array[i] = x;
        i++;
    }

    *length = i;
    return length;
}

int reverse_array(int *array, int *length)
{
    int i = 0, j = *length - 1, temp;

    while(i < j)
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    return 0;
}

int* check_unique_array(int *array, int *length)
{
    static int flag;
    int i, j;

    flag = 1;

    for(i = 0; i < *length; i++)
    {
        for(j = i + 1; j < *length; j++)
        {
            if(array[i] == array[j])
            {
                flag = 0;
                return &flag;
            }
        }
    }

    return &flag;
}

int main()
{
    int len = 0;
    int *length = &len;
    int array[s];
    int *unique, i;

    printf("Max size of an array = 100\n");

    input_array(array, length);

    printf("Array: ");
    for(i = 0; i < *length; i++)
        printf("%d ", array[i]);

    reverse_array(array, length);

    printf("\nAfter reverse: ");
    for(i = 0; i < *length; i++)
        printf("%d ", array[i]);

    unique = check_unique_array(array, length);

    if(*unique == 1)
        printf("\nUnique elements\n");
    else
        printf("\nDuplicates present\n");

    return 0;
}
