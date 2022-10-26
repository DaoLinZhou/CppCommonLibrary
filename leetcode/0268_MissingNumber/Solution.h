//
// Created by jiatang on 2022/7/29.
//

#ifndef CPPCOMMONLIBRARY_SOLUTION_H
#define CPPCOMMONLIBRARY_SOLUTION_H
#include "../commonHeader.h"
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        for(; i<nums.size(); i++){
            if(i != nums[i]){
                return i;
            }
        }
        return i;
    }
};

#endif //CPPCOMMONLIBRARY_SOLUTION_H
