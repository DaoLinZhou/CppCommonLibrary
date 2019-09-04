#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template <typename T>
void selectionSort(T arr[], int n){
    for(int i = 0; i < n; i ++){
        // find min from [i, n)
        int minIndex = i;
        for(int j = i; j < n; j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;
        // swap the min and i
        swap(arr[i], arr[minIndex]);
    }
}