//
// Created by Daolin on 2019/10/12.
//

#include "../commonHeader.h"

// 状态机
/**
 * solution1 的优化, 在Solution1中, 虽然我们创建了数组
 * 但是我们实际上依赖的只是前一个元素, 所以并不一定要创建数组, 只要维护几个变量就可以了
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;

        int sell = 0, buy = -prices[0], rest = 0;
        for (const auto& p : prices) {
            /// 暂存前一个sell的值
            int tmp = sell;
            sell = max(sell, buy + p);
            buy = max(buy, rest - p);

            /// 和前一个sell取max
            rest = max(rest, tmp);
        }
        return max(sell, rest);
    }
};
