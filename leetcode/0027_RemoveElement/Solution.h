//
// Created by Daolin on 2019/11/23.
//
#include "../commonHeader.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val)
                swap(nums[i], nums[k]);
            if(nums[k] != val)
                k++;
        }
        return k;
    }
};
