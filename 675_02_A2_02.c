#include <stdio.h>
#include <stdlib.h>

/* part (i) */
int* input_array(int *size, int *max_size)
{
    int *a = (int*)malloc((*max_size) * sizeof(int));
    int val, i = 0;

    if(a == NULL)
        return NULL;

    printf("Enter values (negative to stop):\n");

    while(i < *max_size)
    {
        scanf("%d", &val);
        if(val < 0)
            break;

        a[i] = val;
        i++;
    }

    *size = i;
    return a;
}

/* part (ii) */
void reverse_array(int *a, int *size)
{
    int i = 0, j = *size - 1, temp;

    while(i < j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

/* part (iii) */
int check_unique_array(int *a, int *size)
{
    int i, j;

    for(i = 0; i < *size; i++)
    {
        for(j = i + 1; j < *size; j++)
        {
            if(a[i] == a[j])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int size = 0, max;
    int *arr, i;

    printf("Enter max size: ");
    scanf("%d", &max);

    arr = input_array(&size, &max);

    if(arr == NULL)
    {
        printf("Memory error\n");
        return 0;
    }

    printf("Array: ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);

    reverse_array(arr, &size);

    printf("\nAfter reverse: ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);

    if(check_unique_array(arr, &size))
        printf("\nUnique elements\n");
    else
        printf("\nDuplicates present\n");

    free(arr);
    return 0;
}
