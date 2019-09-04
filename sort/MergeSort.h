#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include "InsertSort.h"

template <typename T>
void __merge(T arr[], int l, int mid, int r){
    T* aux = new T[r-l+1];
    for(int i=l; i<=r; i++)
        aux[i-l] = arr[i];

    int p = l, q = mid+1;
    for(int k=l; k<=r; k++) {
        if (p > mid) {
            arr[k] = aux[q - l];
            q++;
        } else if (q > r){
            arr[k] = aux[p - l];
            p++;
        }else if(aux[p-l] < aux[q-l]) {
            arr[k] = aux[p - l];
            p++;
        }else {
            arr[k] = aux[q - l];
            q++;
        }
    }

    delete[] aux;
}

template <typename T>
void __mergeSort(T arr[], int l, int r){
//    if(l>=r)
//        return;
    if( r-l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }
    int mid = (r-l)/2+l;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if(arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}



template <typename T>
void mergeSort(T arr[], int n){
    __mergeSort(arr, 0, n);
}

template <typename T>
void mergeSortB2U(T arr[], int n){
    //没有使用数组的一个特性, 通过下标直接获取元素, 可以用nlogn的时间为链表排序
    for(int sz=1; sz <= n; sz += sz)
        for(int i=0; i+sz < n; i += sz+sz)
            __merge(arr, i, i+sz-1, std::min(i+sz+sz-1,n-1));
}

#endif
