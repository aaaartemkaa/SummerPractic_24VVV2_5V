#ifndef SHELL_SORT_H
#define SHELL_SORT_H

void shellSortKnuth(int arr[], int n);
void shellSortVirt(int arr[], int n);
void shellSortDividingInHalf(int arr[], int n);
void printArray(int arr[], int n);
void copyArray(int source[], int dest[], int n);
long long measureTime(void (*sortFunc)(int[], int), int arr[], int n);

#endif