//
// Created by Daolin on 2019/10/21.
//

#include "../commonHeader.h"

class Solution {
private:
    vector<vector<int>> memo;
    int maxCount;

    int tryChange(const vector<int>& wallet, int index, int target){
        if(target == 0)
            return 0;
        if(target < 0 || index >= wallet.size())
            return maxCount;
        if(memo[index][target] != -1)
            return memo[index][target];
        memo[index][target] =  min( 1 + tryChange(wallet, index, target - wallet[index]),
                                    min(tryChange(wallet, index+1, target),
                                        1 + tryChange(wallet, index+1, target - wallet[index])));
        return memo[index][target];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        maxCount = amount+1;
        memo = vector<vector<int>>(coins.size(), vector<int>(amount+1, -1));
        int res = tryChange(coins, 0, amount);
        return res >= maxCount ? -1 : res;
    }
};


