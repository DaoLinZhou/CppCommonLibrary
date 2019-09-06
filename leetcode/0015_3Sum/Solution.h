//
// Created by Daolin on 2019/9/4.
//
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 解题思想
 * 1. 遍历 nums , 把所有元素放入map中,记录每个数字的出现次数
 * 2. 排序并去除 nums 的重复元素
 * 3. 处理特殊情况, 当解的3个元素都一样时, 只有一种可能 {0,0,0}
 * 4. 循环遍历 nums, 假设当前遍历到的元素 nums[i] 是解的一个元素, 在遍历寻找解的第二个元素 nums[j]
 *      4.1 处理解中有两个相同元素的情况, 有两个 nums[i] 或 有两个 nums[j]
 *      4.2 此时再找到的解就是三个元素都互不相同的情况, 确保最后一个元素 c 是在索引 j 的后面, 因为如果在 j 前面我们就考虑过了
 */

class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> counter;
        // <1>
        for(int i=0; i<nums.size(); i++)
            counter[nums[i]] ++;

        // <2>
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        vector<int>::iterator iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());

        // <3>
        if(counter[0] >= 3)
            ret.push_back({0,0,0});

        // <4>
        for(int i=0; i < nums.size(); i++){
            for(int j=i+1; j < nums.size(); j++){
                // <4.1>
                if(nums[i] * 2 + nums[j] == 0 && counter[nums[i]] >= 2)
                    ret.push_back({nums[i], nums[i], nums[j]});
                if(nums[i] + nums[j] * 2 == 0 && counter[nums[j]] >= 2)
                    ret.push_back({nums[i], nums[j], nums[j]});

                // <4.2>
                int c = 0 - nums[i] - nums[j];
                if(c > nums[j] && counter[c] > 0)
                    ret.push_back({nums[i], nums[j], c});
            }
        }
        return ret;
    }
};
