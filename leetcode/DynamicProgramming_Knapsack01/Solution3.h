//
// Created by Daolin on 2019/10/14.
//

#include "../commonHeader.h"

/**
 * Solution2 的优化
 */

class Knapsack01{
private:

public:
    int knapsack01(const vector<int>& w, const vector<int>& v, int C){
        assert(w.size() == v.size());

        int n = w.size();

        if(n == 0 || C == 0)
            return 0;

        vector<vector<int>> memo(2, vector<int>(C+1, -1));
        /// 初始化第一行
        for( int j = 0; j <= C; j++)
            memo[0][j] = (j >= w[0] ? v[0] : 0);
        for(int i = 1; i < n; i++)
            for(int j = 0; j <= C; j++){
                /// 如果不选这个物品
                memo[i%2][j] = memo[(i-1)%2][j];
                /// 如果可以选择并选择了此物品
                if(j >= w[i])
                    memo[i%2][j] = max(memo[i%2][j], v[i] + memo[(i-1)%2][j-w[i]]);
            }
        return memo[(n-1)%2][C];
    }

};
