//
// Created by Daolin on 2019/12/3.
//
#include "../commonHeader.h"

class Solution {
public:
    // [0...k] 其余元素, [k+1...i) 值为val元素
    int removeElement(vector<int>& nums, int val) {
        int k = -1;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != val)
                swap(nums[i], nums[++k]);
        return k+1;
    }
};
