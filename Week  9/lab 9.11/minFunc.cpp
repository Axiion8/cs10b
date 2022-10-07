#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0)
        return nullptr;
    if (arrSize == 1)
        return arr;
    else if (arr[0] < arr[arrSize-1] )
        return min(arr, arrSize-1);
    else
        return min(arr+1, arrSize-1);
}