//
// Created by Daolin on 2019/8/23.
//

#ifndef ALGORITHM_MINHEAP_H
#define ALGORITHM_MINHEAP_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Item>
class MinHeap{
private:
    Item* data;
    int capacity;
    int size;

    void shiftUp(int index){
        while(index > 1 && data[index/2] > data[index]){
            swap(data[index/2], data[index]);
            index /= 2;
        }
    }

    void shiftDown(int index){
        while(index*2 <= size){
            int child = index*2;
            if(child+1 <= size && data[child] > data[child+1])
                child += 1;
            if(data[child] >= data[index])
                break;
            swap(data[child], data[index]);
            index = child;
        }
    }

public:
    MinHeap(int capacity) : capacity(capacity) {
        this->size = 0;
        this->data = new Item[capacity + 1];
    }

    ~MinHeap(){
        delete[] data;
    }

    int getSize(){
        return size;
    }

    int isEmpty(){
        return size == 0;
    }

    void insert(Item item){
        assert(size < capacity);
        data[++ size] = item;
        shiftUp(size);
    }

    Item extractMin(){
        assert(size > 0);
        Item ret = data[1];
        data[1] = data[size --];
        shiftDown(1);
        return ret;
    }

    Item getMin(){
        assert(size > 0);
        return data[1];
    }
};

#endif //ALGORITHM_MINHEAP_H
