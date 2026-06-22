#include "shell_sort.h"
#include <iostream>
#include <ctime>
using namespace std;

void shellSortKnuth(int arr[], int n)
{
    int gap = 1;
    while (gap < n / 3)
    {
        gap = 3 * gap + 1;
    }
    while (gap >= 1)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap = gap / 3;
    }
}

void shellSortVirt(int arr[], int n)
{
    int gap = 1;
    while (gap < n / 3)
    {
        gap = 3 * gap + 1;
    }
    while (gap >= 1)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap = (gap - 1) / 3;
    }
}

void shellSortDividingInHalf(int arr[], int n)
{
    int gap = n / 2;
    while (gap >= 1)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap = gap / 2;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int source[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = source[i];
    }
}

long long measureTime(void (*sortFunc)(int[], int), int arr[], int n)
{
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    return (long long)(end - start);
}