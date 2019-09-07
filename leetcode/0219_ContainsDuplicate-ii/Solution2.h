//
// Created by Daolin on 2019/9/6.
//
#include <vector>
#include <unordered_map>

using namespace std;
/**
 * 解题思路:
 * 遍历nums,
 *      如果以前存储过某一个值, 拿到那个值的index, 用当前i减去它得到的值就是距离,
 *          如果 距离 <= k, 就说明我们找到了符合要求的值 return true
 *      如果没存储过这个值或者距离太远, 更新新的索引
 * 遍历结束都没找到就说明没有符合条件的值
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> record; // 键:记录数值, value: 记录上一个数值的索引
        for(int i = 0; i < nums.size(); i++){
            if(record.find(nums[i]) != record.end() && i - record[nums[i]]<= k)
                return true;
            record[nums[i]] = i;
        }
        return false;
    }

};
