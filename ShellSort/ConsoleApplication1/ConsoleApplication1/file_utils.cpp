#include "file_utils.h"
#include <fstream>
#include <iostream>
using namespace std;

bool readArrayFromFile(const string& filename, int*& arr, int& n)
{
    ifstream file(filename.c_str());
    if (!file.is_open())
    {
        cerr << "Не удалось открыть файл " << filename << endl;
        return false;
    }
    if (!(file >> n))
    {
        cerr << "Файл пуст или не содержит размера" << endl;
        file.close();
        return false;
    }
    if (n <= 0 || n > 100000)
    {
        cerr << "Неверный размер массива (" << n << ")" << endl;
        file.close();
        return false;
    }
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (!(file >> arr[i]))
        {
            cerr << "Недостаточно данных в файле" << endl;
            delete[] arr;
            arr = 0;
            file.close();
            return false;
        }
    }
    file.close();
    return true;
}

bool writeResultsToFile(const string& filename, int arr[], int n,
    long long timeKnuth, long long timeVirt, long long timeDividing)
{
    ofstream file(filename.c_str());
    if (!file.is_open())
    {
        cerr << "Не удалось создать файл " << filename << endl;
        return false;
    }
    file << "Результаты сортировки" << endl;
    file << "Размер массива: " << n << " элементов" << endl << endl;
    file << "Отсортированный массив:" << endl;
    for (int i = 0; i < n; i++)
    {
        file << arr[i] << " ";
        if ((i + 1) % 20 == 0) file << endl;
    }
    file << endl << endl;
    file << "Время сортировки" << endl;
    file << "Метод Кнута:            " << timeKnuth << " тиков" << endl;
    file << "Метод Вирта:            " << timeVirt << " тиков" << endl;
    file << "Метод деления пополам:  " << timeDividing << " тиков" << endl;
    file.close();
    return true;
}

void writeArrayToFile(const string& filename, int arr[], int n, const string& label)
{
    ofstream file(filename.c_str());
    if (!file.is_open()) return;
    file << label << endl;
    for (int i = 0; i < n; i++)
    {
        file << arr[i] << " ";
        if ((i + 1) % 20 == 0) file << endl;
    }
    file << endl;
    file.close();
}