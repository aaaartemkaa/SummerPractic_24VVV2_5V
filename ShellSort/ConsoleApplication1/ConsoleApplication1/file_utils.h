#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>

bool readArrayFromFile(const std::string& filename, int*& arr, int& n);
bool writeResultsToFile(const std::string& filename, int arr[], int n,
    long long timeKnuth, long long timeVirt, long long timeDividing);
void writeArrayToFile(const std::string& filename, int arr[], int n, const std::string& label);

#endif