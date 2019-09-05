//
// Created by Daolin on 2019/9/4.
//
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> counter;

        for(int i=0; i<nums.size(); i++)
            counter[nums[i]] ++;

        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        // 去除数组中重复的元素
        vector<int>::iterator iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());

        // 答案中三个数相同
        if(counter[0] >= 3)
            ret.push_back({0,0,0});

        for(int i=0; i < nums.size(); i++){
            for(int j=i+1; j < nums.size(); j++){
                // 答案中两个数相同
                if(nums[i] * 2 + nums[j] == 0 && counter[nums[i]] >= 2)
                    ret.push_back({nums[i], nums[i], nums[j]});

                if(nums[i] + nums[j] * 2 == 0 && counter[nums[j]] >= 2)
                    ret.push_back({nums[i], nums[j], nums[j]});

                // 此时如果有答案, 那么答案中的三个数一定不相等
                int c = 0 - nums[i] - nums[j];
                if(c > nums[j] && counter[c] > 0)
                    ret.push_back({nums[i], nums[j], c});
            }
        }
        return ret;
    }
};
