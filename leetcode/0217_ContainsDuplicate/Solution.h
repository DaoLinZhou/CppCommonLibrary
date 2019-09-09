//
// Created by Daolin on 2019/9/6.
//

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

//lambda 表达式，可以立即执行，在main函数之前执行，取消输入输出同步，较快输入输出速度
static int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

/**
 * 这题实在太简单了, 懒得写思路了
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2)
            return false;
        unordered_set<int> record;
        for (int num : nums) {
            if(record.find(num) != record.end())
                return true;
            record.insert(num);
        }
        return false;
    }
};
