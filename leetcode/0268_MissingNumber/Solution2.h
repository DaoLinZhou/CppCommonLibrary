//
// Created by jiatang on 2022/7/29.
//

#ifndef CPPCOMMONLIBRARY_SOLUTION_H
#define CPPCOMMONLIBRARY_SOLUTION_H
#include "../commonHeader.h"
class Solution {
public:
    int missingNumber(vector<int>& nums) {
//      首项: 0
//      末项: nums.size()
//      项数: nums.size() + 1
        int sumE = (nums.size()+1)*(nums.size())/2;
        int sumR = 0;
        for (int e : nums){
            sumR += e;
        }
        return sumE -sumR;
    }
};

#endif //CPPCOMMONLIBRARY_SOLUTION_H
