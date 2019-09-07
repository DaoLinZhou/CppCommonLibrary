//
// Created by Daolin on 2019/9/6.
//

#include <vector>
#include <unordered_set>

using namespace std;
/**
 * 由于只要窗口内出现一次重复就可以返回true
 * 所以使用set就可以解决, 不用使用map记录次数
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> record;  // 存储index
        for(int i = 0; i < nums.size(); i++){
            // 如果窗口内存在
            if(record.find(nums[i]) != record.end())
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
