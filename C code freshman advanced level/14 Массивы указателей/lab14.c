#include <stdio.h>
#include <stdlib.h>

void filling_array (int *, int);//заполнение массива
void deleting (int *, int *, int);//удаление элемента массива
void swapping (int *, int, int);//смена местами элементов массива
void output_array (int *, int);//вывод массива
void output_array_pointers(int **mas, int n);
void sort_bubble(int **mas, int n, int size1, int size2);
void QuickSort(int **mas, int n);

int main (void)
{
    int *arr1, *arr2, **arr_p;
    int size1, size2, size_p;
    int i;

    //create first array
    scanf ("%i", &size1);
    arr1 =(int *) malloc(size1 * sizeof(int));
    if (arr1 == NULL)
    {
        printf ("Не удалось выделить память.");
        exit (EXIT_FAILURE);
    }
    filling_array (arr1, size1);

    //create second array
    scanf ("%i", &size2);
    arr2 =(int *) malloc(size2 * sizeof(int));
    if (arr1 == NULL)
    {
        printf ("Не удалось выделить память.");
        exit (EXIT_FAILURE);
    }
    filling_array (arr2, size2);

    //create array with pointers
    size_p = size1 + size2;
    arr_p =(int**) malloc(size_p * sizeof(int*));
    if (arr_p == NULL)
    {
        printf ("Не удалось выделить память.");
        exit (EXIT_FAILURE);
    }

    //filling point array
    for(i = 0; i < size2; i++)
        arr_p[i] = arr2 + i;

    for(i = 0; i < size1; i++)
        arr_p[i + size2] = arr1 + i;

    sort_bubble(arr_p, size_p, size2, size1);

    output_array(arr1, size1);
    printf("\n");
    output_array(arr2, size2);
    printf("\n");

    output_array_pointers(arr_p, size_p);
    printf("\n");

    return 0;
}

void filling_array (int *mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &mas[i]);
    }
}

void deleting (int *mas, int *n, int k)
{
    for (int i = k-1; i < (*n-1); i++)
    {
        mas[i] = mas[i+1];
    }
    --*n;

    int *p;
    p = (int *) realloc(mas, (*n-1) * sizeof(int));
    if (p == NULL)
        printf ("Не удалось уменьшить память.");
    else
        mas = p;
}

void swapping (int *mas, int i, int j)
{
    int t = mas[i];
    mas[i] = mas[j];
    mas[j] = t;
}

void output_array (int *mas, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf ("%3d", i);
    }
    printf ("\n");
    for (int i = 0; i < n; i++)
    {
        printf ("%3d", mas[i]);
    }
    printf ("\n");
}

void output_array_pointers(int **mas, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf ("%3d", i);
    }
    printf ("\n");
    for (int i = 0; i < n; i++)
    {
        printf ("%3d", *(mas[i]));
    }
    printf ("\n");
}

void sort_bubble(int **mas, int n, int size2, int size1)
{
    int *t;
    int i, j;
    for(i = 0; i < size2 / 2; i++)
    {
        //swap
        t = mas[i];
        mas[i] = mas[size2 - 1 - i];
        mas[size2 - 1 - i] = t;
    }

    for( i = 0; i < n; i++)
    {
        for( j = n - 1; j > 0; j--)
        {
            if( *(mas[j]) > *(mas[j - 1]) )
            {
                //swap
                t = mas[j - 1];
                mas[j - 1] = mas[j];
                mas[j] = t;
            }
        }
    }

}

