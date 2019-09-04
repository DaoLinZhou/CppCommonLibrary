//
// Created by Daolin on 2019/6/4.
//
#ifndef INSERTSORT_H
#define INSERTSORT_H

template <typename T>
void insertionSort(T arr[], int n){
    insertionSort(arr, 0, n);
}

template <typename T>
void insertionSort(T arr[], int l, int r){
    for(int i=l+1; i<=r; i++){
        T e = arr[i];
        int j;
        for( j = i; j > l && e < arr[j-1]; j -- )
            arr[j] = arr[j-1];
        arr[j] = e;
    }
}

#endif