#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>

class Sort{
    void Swap(int * value1, int * value2);
    void Merge(std::vector<int> * unsorted, int begin, int pivot, int end);
    int Partition(std::vector<int> * partition, int begin, int end);
    public:
        std::vector<int> * InsertionSort(std::vector<int> unsorted);
        std::vector<int> * QuickSort(std::vector<int> * unsorted, int begin, int end);
        std::vector<int> * MergeSort(std::vector<int> * unsorted, int begin, int end);
};

#endif