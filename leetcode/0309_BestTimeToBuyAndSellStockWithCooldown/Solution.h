//
// Created by Daolin on 2019/10/12.
//

#include "../commonHeader.h"

const int __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

/**
 * 解题思路:
 *
 * buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。
 * sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。
 * rest[i]表示在第i天之前最后一个操作是冷冻期，此时的最大收益。
 *
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;
        int buy[n];
        int sell[n];
        int rest[n];

        /// 初始化第0步时buy只能买入
        buy[0] = -prices[0];

        /// 无法sell或rest
        sell[0] = rest[0] = 0;

        /// 每次对比自身的前一个最大利益, 和自身如果进行操作的利益, 取最大值
        for(int i = 1; i < n;  i++){
            /// buy只会在rest之后进行, 买入会消耗prices[i]的金钱
            buy[i] = max(rest[i-1] - prices[i], buy[i-1]);

            /// sell只会在buy之后进行, 卖出会增加prices[i]的金钱
            sell[i] = max(buy[i-1] + prices[i], sell[i-1]);

            /// rest只会在sell之后进行, 冷却时间什么都不做
            rest[i] = max(sell[i-1], rest[i-1]);
        }

        /// 最后的操作不是买入, 所以从sell和rest中取最大值
        return max(sell[n-1], rest[n-1]);
    }
};
