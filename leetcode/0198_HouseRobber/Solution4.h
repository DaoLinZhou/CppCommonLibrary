//
// Created by Daolin on 2019/10/10.
//
#include "../commonHeader.h"

/**
 * 解题思路:
 * 遍历nums, 记录当前的最佳解, 和前一个值的最佳解
 *
 * 保存curr到temp
 *
 * 每次访问n有两种可能
 *  1. 选取prev+n, 即选取当前房子
 *  2. 不选当前房子, 即curr
 *
 * 取他们中最大的一个赋值给curr
 * 维护 prev, 把temp赋值给prev
 *
 */

class Solution{
public:
    int rob(vector<int>& nums){
        int prev = 0, curr = 0;
        for(int n : nums){
            int temp = curr;

            /// if rob this house, then use prev+n
            /// if don't rob this house, then current will keep the previous amount
            curr = max(prev+n, curr);

            prev = temp;
        }
        return curr;
    }
};
