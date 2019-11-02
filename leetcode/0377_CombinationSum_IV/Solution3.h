//
// Created by Daolin on 2019/10/28.
//

#include "../commonHeader.h"

class Solution {
public:
    /// 对Solution2 的优化
    /// 剪枝操作, 仅仅对所有nums元素能到达的位置进行计算, 跳过无法到达的位置
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> memo = vector<long long>(target+1, 0);
        sort(nums.begin(), nums.end());
        priority_queue<int, vector<int>, greater<int>> queue;
        memo[0] = 1;
        queue.push(0);

        while(!queue.empty()){
            int index = queue.top();
            queue.pop();

            for(int i : nums){
                int next = i + index;
                if(next <= target){
                    if(memo[next] == 0)
                        queue.push(next);
                    memo[next] += memo[index];
                    memo[next] %= INT32_MAX;
                }
            }
        }
        return static_cast<int>(memo[target]);
    }
};
