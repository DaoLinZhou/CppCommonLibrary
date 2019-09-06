//
// Created by Daolin on 2019/9/4.
//
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 解题思路:
 * 1.   排序nums
 * 2.   初始化距离是最大值
 * 3.   遍历 nums, 假设 nums[i] 是其中的一个元素, 寻找其余两个数和距离 target 最近
 * 4.   使用指针碰撞, 如果找到的 sum 值距离 target 更近, 就更新 field 和 isNegative
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // <1> 排序
        sort(nums.begin(), nums.end());

        // <2> field是代表结果值距离target的距离, isNegative是判断距离是向左还是向右
        int field = INT32_MAX;
        bool isNegative = false;

        // <3>
        for(int i = 0; i < nums.size()-2; i++){
            // 跳过重复的元素
            if(i > 0 && nums[i-1] == nums[i])
                continue;

            // 指针碰撞
            int l = i+1, r = nums.size()-1;
            while(l < r){
                int sum = nums[i] + nums[r] + nums[l];
                // <4> 新的距离比旧的距离小
                if(abs(sum-target) < field) {
                    // 更新
                    field = abs(sum - target);
                    isNegative = (sum - target) < 0;
                }
                if(sum < target)
                    l ++;
                else if(sum > target)
                    r --;
                else
                    return target;
            }
        }
        return isNegative ? target - field : target + field;
    }
};
