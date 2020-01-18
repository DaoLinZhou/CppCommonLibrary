//
// Created by Daolin on 2020/1/17.
//
#include "../commonHeader.h"

class Solution {
public:

    bool containZero(int n){
        while(n % 10 != 0){
            n /= 10;
        }
        return n != 0;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            if(!containZero(i) && !containZero(n-i)){
                return {i, n-i};
            }
        }
        return {};
    }
};
