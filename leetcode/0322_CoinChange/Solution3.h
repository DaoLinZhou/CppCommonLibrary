//
// Created by Daolin on 2019/10/23.
//
#include "../commonHeader.h"

class Solution {
private:
    vector<int> memo;
    int maxCount;

    /// 尝试用coins 填充amount
    int tryChange(const vector<int>& coins, int amount){
        if(amount == 0)
            return 0;
        if(memo[amount] != -1)
            return memo[amount];
        int res = maxCount;
        for(int coin: coins)
            /// 如果可以使用这枚硬币, 就尝试使用它
            if(amount - coin >= 0)
                res = min(res, 1 + tryChange(coins, amount - coin));
        return memo[amount] = res;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        maxCount = amount+1;
        memo = vector<int>(amount+1, -1);
        int res = tryChange(coins, amount);
        return res >= maxCount ? -1 : res;
    }
};
