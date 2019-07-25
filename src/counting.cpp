#include "Sort.h"

std::vector<int> * Sort::CountingSort(std::vector<int> unsorted){
    std::vector<int> auxiliar;
    std::vector<int> * sorted = new std::vector<int>(unsorted.size());
    int max = 0;

    for(int i = 0; i < unsorted.size();i++){
        if(unsorted[i] > max)
            max = unsorted[i];
    }

    auxiliar = std::vector<int>(max+1,0);

    for(int i = 0; i < unsorted.size();i++){
        auxiliar[unsorted[i]]++;
    }

    for(int i = 1; i < auxiliar.size();i++){
        auxiliar[i] += auxiliar[i-1];
    }

    for(int i = unsorted.size()-1; i >= 0 ;i--){
        sorted->at(--auxiliar[unsorted[i]]) = unsorted[i];
    }

    return sorted;
}