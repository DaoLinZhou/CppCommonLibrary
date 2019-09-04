//
// Created by Daolin on 2019/6/13.
//

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

#include <iostream>
#include "SortTestHelper.h"
#include "InsertSort.h"
#include "MergeSort.h"
#include <stack>

using namespace std;
template <typename T>
int __partition(T arr[], int l,int r){
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T e = arr[l];
    int p = l;
    for(int i = l+1; i <= r; i++)
        if(arr[i] < e)
            swap(arr[++p], arr[i]);
    swap(arr[l], arr[p]);
    return p;
}

template <typename T>
void __quickSort(T arr[], int l, int r){
//    if(l>=r)
//        return;
    if(r-l > 15){
        insertionSort(arr, l, r);
        return;
    }
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}



template <typename T>
int __partition2(T arr[], int l,int r){
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    int p = l+1, q = r;
    T e = arr[l];
    while (true){
        while (p<=r && arr[p] < e) p++;
        while (q>=l+1 && arr[q] > e) q--;
        if(p > q) break;
        swap(arr[p], arr[q]);
        p++;
        q--;
    }
    swap(arr[l], arr[q]);
    return q;
}

template <typename T>
void __quickSort2(T arr[], int l, int r){
    if(l>=r)
        return;
//    if(r-l > 15){
//        insertionSort(arr, l, r);
//        return;
//    }
    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);
}

template <typename T>
void quickSort2(T arr[], int n){
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}


template <typename T>
void __quickSort3(T arr[], int l, int r){
    if(l>=r)
        return;
//    if(r-l > 15){
//        insertionSort(arr, l, r);
//        return;
//    }
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T e = arr[l];
    int lt=l+1, q=l+1, gt=r;
    while (q <= gt){
        if(arr[q] == e)
            q++;
        else if(arr[q] < e){
            swap(arr[lt], arr[q]);
            lt++;
            q++;
        }
        else{
            swap(arr[q], arr[gt]);
            gt--;
        }

    }
    swap(arr[l], arr[lt-1]);

    __quickSort3(arr, l, lt-2);
    __quickSort3(arr, gt+1, r);
}

template <typename T>
void quickSort3(T arr[], int n){
    srand(time(NULL));
    __quickSort3(arr, 0, n-1);
}


template <typename T>
void __partition(T arr[], stack<int> *st){
    //先取出右边界, 再取出左边界
    int r = st->top();
    st->pop();
    int l = st->top();
    st->pop();

    if(l>=r)
        return;

    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    int lt = l+1, k = l+1, gt = r;
    while(k <= gt){
        if(arr[k] == v){
            k++;
        }else if(arr[k] < v){
            swap(arr[k++], arr[lt++]);
        }else{
            swap(arr[k], arr[gt--]);
        }
    }
    swap(arr[l], arr[lt-1]);

    st->push(l);
    st->push(lt-2);
    st->push(gt+1);
    st->push(r);
}

template <typename T>
void quickSortLoop(T arr[], int n){
    srand(time(0));
    stack<int> *st = new stack<int>();
    //先放左边界, 再放右边界
    st->push(0);
    st->push(n-1);
    while(!st->empty()){
        __partition(arr, st);
    }
}

#endif //ALGORITHM_QUICKSORT_H
