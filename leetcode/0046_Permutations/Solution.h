//
// Created by Daolin on 2019/9/25.
//
#include <vector>

using namespace std;

/**
 * 解题思路:
 * 回溯法:
 * 遍历数组, 如果当前元素没有使用过, 就向下递归求解, 递归到底就把求得的解放入解集中
 * 注意回溯一定要返回原来的状态
 */

class Solution {
private:
    vector<vector<int>> res = {};
    vector<bool> used;

    // p保存了一个有index个元素的排列
    // 向这个排列的末尾添加第index+1个元素, 获得一个有index+1个元素的排列
    void generatePermutation(const vector<int>& nums, int index, vector<int>& p){
        if(index == nums.size()){
            res.push_back(p);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if( !used[i] ){     // 没有使用过
                p.push_back(nums[i]);
                used[i] = true;
                generatePermutation(nums, index + 1, p);

                // 恢复原状, 回溯, 返回原来的状态
                p.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return res;
        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation(nums, 0, p);

        return res;
    }
};
