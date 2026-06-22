#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "shell_sort.h"
#include "file_utils.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int* original = 0;
    int size;
    int choice;
    cout << "Сортировка Шелла: Кнут, Вирт, Деление пополам" << endl;
    cout << "Выберите источник данных:" << endl;
    cout << "1 - Сгенерировать случайный массив" << endl;
    cout << "2 - Прочитать массив из файла (input.txt)" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    while (cin.fail() || (choice != 1 && choice != 2))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите 1 или 2: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        cout << "Введите размер массива: ";
        cin >> size;
        while (cin.fail() || size <= 0 || size > 100000)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Размер должен быть от 1 до 100000! Введите заново: ";
            cin >> size;
        }
        original = new int[size];
        for (int i = 0; i < size; i++)
        {
            original[i] = rand() % 1000;
        }
        cout << endl << "Сгенерирован массив из " << size << " элементов" << endl;
    }
    else if (choice == 2)
    {
        if (!readArrayFromFile("input.txt", original, size))
        {
            cout << "Ошибка при чтении файла!" << endl;
            cout << "Нажмите Enter для выхода...";
            cin.ignore();
            cin.get();
            return 1;
        }
        cout << endl << "Прочитан массив из " << size << " элементов" << endl;
    }
    cout << "Исходный массив: ";
    printArray(original, size);
    cout << endl;
    int* arrKnuth = new int[size];
    int* arrVirt = new int[size];
    int* arrDividing = new int[size];
    copyArray(original, arrKnuth, size);
    copyArray(original, arrVirt, size);
    copyArray(original, arrDividing, size);
    long long timeKnuth = measureTime(shellSortKnuth, arrKnuth, size);
    long long timeVirt = measureTime(shellSortVirt, arrVirt, size);
    long long timeDividing = measureTime(shellSortDividingInHalf, arrDividing, size);
    cout << "Результаты сортировки" << endl;
    cout << "Отсортированный массив (Кнут): ";
    printArray(arrKnuth, size);
    cout << "Отсортированный массив (Вирт): ";
    printArray(arrVirt, size);
    cout << "Отсортированный массив (Деление пополам): ";
    printArray(arrDividing, size);
    cout << endl;
    cout << "Время сортировки:" << endl;
    cout << "Метод Кнута:            " << timeKnuth << " тиков" << endl;
    cout << "Метод Вирта:            " << timeVirt << " тиков" << endl;
    cout << "Метод деления пополам:  " << timeDividing << " тиков" << endl;
    cout << endl << "Запись результатов в файл output.txt..." << endl;
    if (writeResultsToFile("output.txt", arrKnuth, size, timeKnuth, timeVirt, timeDividing))
    {
        cout << "Результаты успешно записаны в output.txt" << endl;
    }
    writeArrayToFile("sorted_knuth.txt", arrKnuth, size, "Сортировка Шелла (Кнут):");
    writeArrayToFile("sorted_virt.txt", arrVirt, size, "Сортировка Шелла (Вирт):");
    writeArrayToFile("sorted_dividing.txt", arrDividing, size, "Сортировка Шелла (Деление пополам):");
    delete[] original;
    delete[] arrKnuth;
    delete[] arrVirt;
    delete[] arrDividing;
    cout << "\nНажмите Enter для выхода...";
    cin.ignore();
    cin.get();
    return 0;
}