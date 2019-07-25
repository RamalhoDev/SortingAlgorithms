#include "Sort.h"

std::vector<int> * Sort::MergeSort(std::vector<int> * unsorted, int begin, int end){
    if(begin < end){
        int pivot = (end + begin)/2.0;
        MergeSort(unsorted, begin, pivot);        
        MergeSort(unsorted, pivot+1, end);
        Merge(unsorted, begin, pivot, end);
    }
    return unsorted;
}

void Sort::Merge(std::vector<int> * unsorted, int begin, int pivot, int end){
    // printf("begin: %d | end: %d | pivot: %d\n", begin, end, pivot);
    int sizeLeft = pivot - begin + 1;
    int sizeRight = end - pivot;
    int a = 0 , b = 0, flag = 0;

    std::vector<int> left;   
    std::vector<int> right;
    
    for(int i = 0; i < sizeLeft; i++){
        left.push_back(unsorted->at(begin+i));
    }
    
    for(int i = 0; i < sizeRight; i++){
        if(pivot+i+1 < unsorted->size())
            right.push_back(unsorted->at(pivot+i+1));
    }
    left.push_back(INT32_MAX);
    right.push_back(INT32_MAX);
      
    if(right.empty()) flag = 1;

    for (size_t i = begin; i < end+1&& i < unsorted->size(); i++)
    {   
        if((flag || left[a] < right[b])){
            unsorted->at(i) = left[a];
            a++;
        }else{
            unsorted->at(i) = right[b];
            b++;
        }
    }
}