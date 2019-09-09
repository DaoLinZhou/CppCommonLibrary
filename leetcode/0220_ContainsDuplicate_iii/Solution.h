//
// Created by Daolin on 2019/9/7.
//
#include <vector>
#include <set>

using namespace std;

/**
 * 解题思路:
 * 和 219号问题的思路大致一样, 但由于需要求lower_bound(floor)
 * 所以需要集合具有顺序性, 不能使用 unordered_set 而使用 set
 */

// Time complexity O(nlogn)
// Space complexity O(k)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> record;  // 需要有顺序性
        for(int i = 0; i < nums.size(); i++){
//            if(record.find(nums[i]) != record.end())
//                return true;
            /**
             *  如果有大于等于nums[i] - t 的元素, 同时这个元素小于等于nums[i] + t, 就说明找到了
             *  有可能会出现整型溢出, 所以要转换成long long进行计算
             */
            auto it = record.lower_bound((long long)nums[i] - (long long)t);
            if(it != record.end() && *it <= (long long)nums[i] + (long long)t)
                return true;
            // 不存在就添加
            record.insert(nums[i]);
            // 窗口内最多有k+1个元素, 如果满了要删除最左边的那个, 来为下一个提供位置
            if(record.size() == k+1)
                record.erase(nums[i-k]);
        }
        return false;
    }
};
