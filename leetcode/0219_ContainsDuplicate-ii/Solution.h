//
// Created by Daolin on 2019/9/6.
//
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 解题思路:
 * 只有添加操作可能会导致滑动窗口内出现重复元素,
 *      如果出现重复元素一定是新添加的那个元素重复了
 * 所以每次添加时都要检查添加元素的那个位置
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 2 || k <= 0)
            return false;
        unordered_map<int, int> record;     // key 为数值, value为次数
        // 先放入滑动窗口内的值, 如果出现重复就return true;
        for(int i=0; i < nums.size() && i <= k; i++)
            if(increase(record, nums[i])) return true;
        // 进行窗口滑动, 先删除左边元素, 在添加右边元素, 保证窗口不越界
        int l=0, r=k;
        while(r < nums.size()-1){
            record[nums[l++]] --;
            if(increase(record, nums[++r])) return true;
        }
        return false;
    }

private:
    // 每次添加都检查这次添加是否会导致有两个相同的值同时出现
    bool increase(unordered_map<int, int>& record, int i){
        record[i]++;
        return record[i] >= 2;
    }
};
