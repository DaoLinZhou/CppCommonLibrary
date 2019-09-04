//
// Created by Daolin on 2019/6/14.
//

#ifndef ALGORITHM_NTHNUMBER_H
#define ALGORITHM_NTHNUMBER_H

#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
int __quickSort(T arr[], int l, int r, int rank){
    if(l >= r)
        return arr[l];
    swap(arr[l], arr[rand()%(r-l)+l]);
    T v = arr[l];
    int lt = l+1, gt = r, q = l+1;
    while(q <= gt){
        if(arr[q] == v)
            q++;
        else if(arr[q] > v)
            swap(arr[q], arr[gt--]);
        else
            swap(arr[q++], arr[lt++]);
    }
    swap(arr[l], arr[lt-1]);

    if(rank >= lt && rank < q) {
        //cout << rank << " " << lt << ", " << gt << endl << "number:" << arr[lt] << endl;
        return arr[lt];
    }else if(rank <= (lt-1))
        return __quickSort(arr, l, lt - 1, rank);
    else
        return __quickSort(arr, q, r, rank);
}

template <typename T>
// n        数组长度
// rank     希望获取第 rank 大的元素 从 1 到 n
int getNthNumber(T arr[], int n, int rank){
    srand(time(NULL));
    return __quickSort(arr, 0, n-1, n-rank);
}

#endif //ALGORITHM_NTHNUMBER_H
