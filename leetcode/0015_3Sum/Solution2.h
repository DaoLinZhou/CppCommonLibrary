//
// Created by Daolin on 2019/9/4.
//
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 解题思路:
 * 1.   判断特殊情况, nums 的长度小于3
 * 2.   对数组进行排序
 * 3.   遍历数组, 确保 nums[i] 以前没找过, 假设 nums[i] 是解的其中一个元素, 寻找另外两个元素
 * 4.   使用碰撞指针的技术寻找解
 * 5.   如果找到了一个解, 则跳过重复元素接着找下一个解, 知道指针碰撞到一起
 */

// using two pointer
// Time complexity O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // <1>
        if(nums.size()<3)
            return {};
        // <2>
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;
        // <3>
        for(int i = 0; i < nums.size(); i++){
            // nums[i] 大于0, 则它之后的所有元素都大于0
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i-1] == nums[i])   // 同一个元素不选2次
                continue;
            // <4> 碰撞指针查找元素
            int l = i+1, r = nums.size()-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < 0)
                    l ++;
                else if(sum > 0)
                    r --;
                else{
                    ret.push_back({nums[i], nums[l], nums[r]});
                    // <5> 跳过所有相同的结果
                    int lvalue = nums[l], rvalue = nums[r];
                    while(l < r && nums[l] == lvalue) l++;
                    while(l < r && nums[r] == rvalue) r--;
                }
            }
            return ret;
        }
    }
};