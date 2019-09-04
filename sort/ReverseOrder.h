//
// Created by Daolin on 2019/6/14.
//

#ifndef ALGORITHM_REVERSEORDER_H
#define ALGORITHM_REVERSEORDER_H

#include <iostream>
#include "SortTestHelper.h"


using namespace std;

template <typename T>
long long __merge(T arr[], int l, int mid ,int r){
    T* aux = new T[r-l+1];
    for(int i=l; i<=r; i++)
        aux[i-l] = arr[i];

    long long count = 0;
    int p=l, q = mid+1;
    for(int i = l; i <= r; i++){
        if(p > mid){
            arr[i] = aux[q - l];
            q++;
        }else if(q > r){
            arr[i] = aux[p - l];
            p++;
        }else if(aux[p - l] > aux[q - l]){    //左边大于右边
            arr[i] = aux[q - l];
            count += mid-p+1;
            q++;
        }else{                                //右边大于左边
            arr[i] = aux[p - l];
            p++;
        }
    }

    delete[] aux;
    return count;
}

template <typename T>
long long merge(T arr[], int l, int r){
    if (l>=r)
        return 0;
    int mid = (r-l)/2 + l;
    long long count_1 = merge(arr, l, mid);
    long long count_2 = merge(arr, mid+1, r);
    long long count = __merge(arr, l, mid, r);

    return count_1+count_2+count;
}

template <typename T>
long long sortAndGetReverseOrder(T arr[], int n){
    return merge(arr, 0, n-1);
}

#endif //ALGORITHM_REVERSEORDER_H
