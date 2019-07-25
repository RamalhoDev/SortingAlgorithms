#include "Sort.h"

std::vector<int> * Sort::QuickSort(std::vector<int> * unsorted, int begin, int end){
    if(begin < end-1){
        int pivot = Partition(unsorted, begin, end);
        unsorted = QuickSort(unsorted, pivot+1, unsorted->size());
        unsorted = QuickSort(unsorted, begin, pivot);        
    }
    return unsorted;
}

void Sort::Swap(int * value1, int * value2){
    int aux = *value1;
    *value1 = *value2;
    *value2 = aux;
}

int Sort::Partition(std::vector<int> * partition, int begin, int end){
    int pivot = partition->at(begin), i = begin-1, j = end;
    
    while(true){
        do{
            i++;
            if(i == end)
                break;
        }while( partition->at(i) <= pivot );

        do{
            j--;     
        }while(partition->at(j) > pivot);

        if(j <= i)
            break;
        Swap(&partition->at(i), &partition->at(j));
    }
    Swap(&partition->at(begin), &partition->at(j));
    return j;
}