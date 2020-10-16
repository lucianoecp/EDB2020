#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <locale.h>

#define TAM 1000

// Data 
void ShowData(int v[], int n);
void GenerateData(int v[], int n);
void CopyData(int v1[], int v2[], int n);

// Sort
void BubbleSort(int v[], int n);
void SelectionSort(int v[], int n);
void InsertionSort(int v[], int n);

int main ()
{
    setlocale(LC_ALL, "");

    clock_t t_o, t_f;

    float t_B;
    float t_S;
    float t_I;

    int data[TAM], aux[TAM];

    GenerateData(data, TAM);
    ShowData(data, TAM);
    
    // Bubble Sort:
    CopyData(data, aux, TAM);

    t_o = clock();
    BubbleSort(data, TAM);
    t_f = clock();
    t_B = (difftime(t_f, t_o));

    // Selection Sort:
    CopyData(aux, data, TAM);

    t_o = clock();
    SelectionSort(data, TAM);
    t_f = clock();
    t_S = (difftime(t_f, t_o));

    // Insertion Sort:
    CopyData(aux, data, TAM);

    t_o = clock();
    InsertionSort(data, TAM);
    t_f = clock();
    t_I = (difftime(t_f, t_o));

    ShowData(data, TAM);

    // Report
    printf("\nSorting time for BubbleSort: %2.f ms", t_B);
    printf("\nSorting time for SelectionSort: %2.f ms", t_S);
    printf("\nSorting time for InsertionSort: %2.f ms", t_I);
    printf("\n\n");

    return 0;
}

void GenerateData(int v[], int n)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        v[i] = rand() % 9999;
    }
    printf("\n>> Generated data:\n\n");
}

void ShowData(int v[], int n)
{
    int i, j, c = 0;
    printf("\n\nDisplaying Data: \n");

    for (j = 0; j < n; j++)
    {
        printf(" [%4d]", v[c]);
        c++;

        if ((j + 1) % 10 == 0)
            printf("\n");
    }
    printf("\nTotal number of data: %d \n", c);
}

void CopyData(int v1[], int v2[], int n)
{
    printf("\n\n copying data");

    int i;
    for(i = 0 ; i < n; i ++)
    {
        v2[i] = v1[i];
    }

    printf("... [done!]\n");
}

void BubbleSort(int v[], int n)
{
    int pass, i, temp, swapped =1;
    for(pass = n - 1; pass >= 0 && swapped; pass--)
    {
        swapped = 0;
        for(i = 0; i <= pass - 1; i++)
        {
            if(v[i] > v[i+1])
            {
                // swap
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                swapped = 1;
            }
        }
    }

    printf("\n Sorting by bubble method [done!]\n");
}

void SelectionSort(int v[], int n)
{
    int i, j, min, temp;
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(v[j] < v[min])
            {
                min = j;
            }
        }
        // swap
        temp = v[min];
        v[min] = v[i];
        v[i] = temp;
    }
    printf("\n Sorting by selection method [done!]\n");
}

void InsertionSort(int v[], int n)
{
    int i, j, x;
    for(i = 1; i <= n-1; i++)
    {
        x = v[i];
        j = i;
        while (v[j-1] > x && j >= 1) 
        {
            v[j] = v[j-1];
            j--;
        }
        v[j] = x;
    }
    printf("\n Sorting by insertion method [done!]\n");
}