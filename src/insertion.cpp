#include "Sort.h"

std::vector<int> * Sort::InsertionSort(std::vector<int> unsorted){
    size_t size = unsorted.size();
    std::vector<int> * sorted = new std::vector<int>();
    size_t count = 0;
    int aux, pos;

    for (size_t i = 0; i < size; i++)
    {
        sorted->push_back(unsorted[i]);
        count++;
        pos = count-1;
        for(int j = count-2; j >= 0; j--){
            if(sorted->at(pos) < sorted->at(j)){
                aux = sorted->at(j);
                sorted->at(j) = sorted->at(pos);
                sorted->at(pos) = aux;
                pos = j;
                continue;
            }
            break;
        }
    }

    return sorted;
}