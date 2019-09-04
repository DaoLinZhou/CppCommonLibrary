//
// Created by Daolin on 2019/6/4.
//

#ifndef ALGORITHM_SORTTESTHELPER_H
#define ALGORITHM_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{

    // 生成有n个元素的随机数组, 每个元素的随机范围为[rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR){

        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(0));
        for(int i = 0; i < n; i++)
            arr[i] = static_cast<int>((rand() / double(RAND_MAX)) * (rangeR - rangeL + 1) + rangeL);
        return arr;
    }

    int* generateNearlyOrderedArray(int n, int swapTime){
        int* arr = new int[n];
        for( int i = 0; i < n; i++)
            arr[i] = i;
        srand(time(0));
        for(int i = 0; i < swapTime; i++){
            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx], arr[posy]);
        }

        return arr;
    }

    template <typename T>
    void printArray(T arr[], int n){
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout<<endl;
        return;
    }

    template <typename T>
    bool isSorted(T arr[], int n){
        for(int i = 0; i < n-1; i++)
            if(arr[i] > arr[i+1]){
                //printArray(arr,n);
                return false;
            }
        return true;
    }


    template <typename T>
    void testSort( string sortName, void(*sort)(T[], int), T arr[], int n ){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));

        cout << sortName << "  :  " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

        return;
    }

    int* copyIntArray(int a[], int n){
        int* arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }

}

#endif //ALGORITHM_SORTTESTHELPER_H
