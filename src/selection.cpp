#include "Sort.h"

std::vector<int> * Sort::SelectionSort(std::vector<int> unsorted){
    std::vector<int> * sorted = new std::vector<int>(unsorted);
    int min = -1;
    for(int i = 0; i < sorted->size(); i++){
        min = i;
        for(int j = i+1; j < sorted->size(); j++){
            if(sorted->at(j) < sorted->at(min)){
                min = j;
            }
        }
        if(sorted->at(i) != sorted->at(min)) Swap(&sorted->at(i), &sorted->at(min));
    }
    return sorted;
}