//
// Created by Daolin on 2019/6/16.
//

#ifndef ALGORITHM_HEAP_H
#define ALGORITHM_HEAP_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

template <typename T>
class MaxHeap{
public:
    MaxHeap(int capacity) : capacity(capacity) {
        size = 0;
        data = new T[capacity+1];
    }

    MaxHeap(const int arr[], int n){
        data = new T[n+1];
        capacity = n;
        for(int i=0; i < n; i++)
            data[i+1] = arr[i];
        size = n;
        for(int i = n/2; i >= 1; i--)
            shiftDown(i);
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    void insert(T item){
        assert(size < capacity);
        data[++size] = item;
        shiftUp(size);
    }

    T extractMax(){
        assert(size > 0);
        T ret = data[1];
        swap(data[1], data[size--]);
        shiftDown(1);
        return ret;
    }


    virtual ~MaxHeap() {
        delete[] data;
    }

private:
    int capacity;
    T* data;
    int size;

    void shiftUp(int index){
        while(data[index/2] < data[index] && index > 1){
            swap(data[index/2], data[index]);
            index /= 2;
        }
    }

    //待优化: swap 可以改为赋值, 插入排序的优化
    void shiftDown(int index){
        while(index*2 <= size){
            int j = index*2;
            if(j+1 <= size && data[j] < data[j+1])
                j++;
            if(data[index] >= data[j])
                break;
            swap(data[index], data[j]);
            index = j;
        }
    }

};

#endif //ALGORITHM_HEAP_H
