//
// Created by Daolin on 2019/9/4.
//
#include <vector>
#include <algorithm>

using namespace std;

// using two pointer
// Time complexity O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i = 0; i < nums.size(); i++){
            // nums[i] 大于0, 则它之后的所有元素都大于0
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i-1] == nums[i])   // 同一个元素不选2次
                continue;
            // 碰撞指针查找元素
            int l = i+1, r = nums.size()-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < 0)
                    l ++;
                else if(sum > 0)
                    r --;
                else{
                    ret.push_back({nums[i], nums[l], nums[r]});
                    // 跳过所有相同的结果
                    int lvalue = nums[l], rvalue = nums[r];
                    while(l < r && nums[l] == lvalue) l++;
                    while(l < r && nums[r] == rvalue) r--;
                }
            }
            return ret;
        }
    }
};