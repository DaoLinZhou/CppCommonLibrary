//
// Created by Daolin on 2019/9/25.
//
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 解题思路:
 * 和46号问题大致相同, 唯一的区别就是每次遍历, 不遍历重复的元素,
 * 因此使用map即可过滤重复元素, 还可以记录元素剩余可以使用的次数, 因为有重复元素, 所以同一个元素可以多次使用
 */

class Solution {
private:
    vector<vector<int>> res = {};
    unordered_map<int, int> map;

    void permuteHelper(const int& size, const int& index, vector<int>& p){
        if(index == size){
            res.push_back(p);
            return;
        }
        // 和46号问题的最大区别就是不遍历相同的元素, 因此使用map
        for(auto i : map){
            if(i.second > 0){   // 确保map中还有这个元素(没有在之前的过程中使用掉)
                map[i.first] --;
                p.push_back(i.first);
                permuteHelper(size, index+1, p);

                // 返回原来的状态
                map[i.first] ++;
                p.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i : nums)
            map[i] ++;
        vector<int> p;
        permuteHelper(nums.size(), 0, p);
        return res;
    }

};
