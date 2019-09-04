//
// Created by Daolin on 2019/7/5.
//

#ifndef ALGORITHM_BINARYSEARCH_H
#define ALGORITHM_BINARYSEARCH_H


//二分查找法, 在有序数组中查找target
//经典循环实现
template <typename T>
int binarySearchLoop(T arr[], int n, T target){
    int l=0, r=n-1;
    while(l <= r){
//        int mid = (l+r)/2;
        int mid = l + (r-l)/2;
        if(arr[mid] > target)
            r = mid-1;
        else if(arr[mid] < target)
            l = mid+1;
        else
            return mid;
    }
    return -1;
}


template <typename T>
int _binarySearch(T arr[], int l, int r, T target){
    if(l > r)
        return -1;
    int mid = l+(r-l)/2;
    if(arr[mid] > target)
        return _binarySearch(arr, l, mid-1, target);
    else if(arr[mid] < target)
        return _binarySearch(arr, mid+1, r, target);
    else
        return mid;
}

template <typename T>
int binarySearch(T arr[], int n, T target){
    return _binarySearch(arr, 0, n-1, target);
}


template <typename T>
int floor(T arr[], int n, T target){
    int l=0, r=n-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(arr[mid] > target)
            r = mid-1;
        else if(arr[mid] < target)
            l = mid+1;
        else{
            for(int i=mid-1; i>=l; i--) {
                if (arr[i] != target)
                    return i + 1;
                if (i == l)
                    return l;
            }
        }
    }
    return r;
}

template <typename T>
int ceil(T arr[], int n, T target){
    int l=0, r=n-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(arr[mid] > target)
            r = mid-1;
        else if(arr[mid] < target)
            l = mid+1;
        else{
            for(int i=mid+1; i<=r; i++) {
                if (arr[i] != target)
                    return i - 1;
                if (i == r)
                    return r;
            }
        }
    }
    return l;
}

#endif //ALGORITHM_BINARYSEARCH_H
