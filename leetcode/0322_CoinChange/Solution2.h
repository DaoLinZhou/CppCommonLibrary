//
// Created by Daolin on 2019/10/23.
//

#include "../commonHeader.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxCount = amount+1;
        vector<int> memo = vector<int>(amount+1, maxCount);
        memo[0] = 0;

        for(int coin: coins)
            /// 这里只需要计算比这个coin大的值就行, 比这个coin小的不需要改变, 因为这时必定选择不了这个coin
            for(int j = coin ; j <= amount ; j ++)
                memo[j] = min(memo[j], memo[j-coin] + 1);

        int res = memo[amount];
        return res != maxCount ? res : -1;
    }
};
