//
// Created by Daolin on 2019/8/24.
//

#ifndef ALGORITHM_INDEXMINHEAP_H
#define ALGORITHM_INDEXMINHEAP_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Item>
class IndexMinHeap{
private:
    int size;
    int capacity;
    int* index;
    Item* data;
    int* rev;

    void shiftUp(int i){
        while(i > 1 && data[index[i]] < data[index[i/2]]){
            swap(index[i], index[i/2]);
            rev[index[i/2]] = i/2;
            rev[index[i]] = i;
            i = i/2;
        }
    }

    void shiftDown(int i){
        while(i*2 <= size){
            int j = i*2;
            if(j+1 <= size && data[index[j]] > data[index[j+1]]) j++;
            if(data[index[i]] <= data[index[j]]) break;
            swap(index[i], index[j]);
            rev[index[i]] = i;
            rev[index[j]] = j;
            i = j;
        }
    }

public:
    IndexMinHeap(int n):capacity(n){
        size = 0;
        index = new int[n+1];
        data = new Item[n+1];
        rev = new int[n+1];

        for(int i = 0; i <= capacity; i++)
            rev[i] = 0;
    }

    ~IndexMinHeap(){
        delete[] index;
        delete[] data;
        delete[] rev;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }



    // 对于用户来说i从0开始
    void insert(int i, Item item){
        assert(size < capacity);
        assert(i >= 0 && i < capacity);
        i++;
        data[i] = item;
        index[++ size] = i;
        rev[i] = size;
        shiftUp(size);
    }

    Item extractMin(){
        assert(size > 0);
        Item ret = data[index[1]];
//        index[1] = index[size];
        swap( index[1] , index[size] );
        rev[index[1]] = 1;
        rev[index[size]] = 0;
        size --;
        shiftDown(1);
        return ret;
    }

    int extractMinIndex(){
        assert(size > 0);
        int ret = index[1] - 1;
        swap(index[1], index[size]);
        rev[index[1]] = 1;
        rev[index[size]] = 0;
        size--;
        shiftDown(1);
        return ret;
    }

    Item getMax(){
        assert(size > 0);
        return data[index[1]];
    }

    bool contain(int i){
        assert(i >= 0 && i < capacity);
        return rev[i+1] != 0;
    }

    Item getItem(int i){
        assert(contain(i));
        return data[i+1];
    }

    void change(int i, Item newItem){
        assert(contain(i));
        i++;
        data[i] = newItem;
        int j = rev[i];
        shiftDown(j);
        shiftUp(j);
    }


};

#endif //ALGORITHM_INDEXMINHEAP_H
