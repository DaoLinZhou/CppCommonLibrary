//
// Created by Daolin on 2019/6/19.
//

#ifndef ALGORITHM_HEAPSORT_H
#define ALGORITHM_HEAPSORT_H

#include <iostream>
#include "../heap/MaxHeap.h"

using namespace std;

template <typename T>
void heapSort1(T arr[], int n){
    MaxHeap<int> *maxHeap = new MaxHeap<int>(n+1);
    for(int i=0; i<n; i++)
        maxHeap->insert(arr[i]);
    for(int i = n-1; i >= 0; i--)
        arr[i] = maxHeap->extractMax();
}

template <typename T>
void heapSort2(T arr[], int n){
    MaxHeap<int> *maxHeap = new MaxHeap<int>(arr, n);
    for(int i = n-1; i >= 0; i--)
        arr[i] = maxHeap->extractMax();
}

template <typename T>
void __shiftDown(T arr[], int n, int i) {
    while(i*2+1 < n){
        int j = i*2+1;
        if(j+1 < n && arr[j+1] > arr[j])
            j += 1;
        if(arr[i] >= arr[j])
            break;
        swap(arr[i], arr[j]);
        i = j;
    }

}

template <typename T>
void heapSort(T arr[], int n){
    //heapify
    for(int i = (n-1) / 2; i >= 0; i--)
        __shiftDown(arr, n, i);
    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}

#endif //ALGORITHM_HEAPSORT_H
