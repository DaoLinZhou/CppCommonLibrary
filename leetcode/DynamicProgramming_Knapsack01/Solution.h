//
// Created by Daolin on 2019/10/12.
//
#include "../commonHeader.h"

/**
 * 背包问题:
 *
 *  有一个背包, 他的容量为C, 现有n种不同物品,
 *  编号0...n-1 , 其中每件物品重量为w(i), 价值为v(i).
 *  问可以向这个背包中放入哪些物品, 使得在不超过背包容量的基础上, 物品的总价值最大
 *  返回最大值
 */

class Knapsack01{
private:
    vector<vector<int>> memo;

    // 用[0...index]的物品
    int bestValue(const vector<int>& w, const vector<int>& v, int index, int c){
        if(index < 0 || c <= 0)
            return 0;
        if(memo[index][c] != -1)
            return memo[index][c];
        int res = bestValue(w, v, index-1, c);
        if(c >= w[index])
            res = max(res, v[index] + bestValue(w, v, index-1, c-w[index]));
        memo[index][c] = res;
        return res;
    }
public:
    int knapsack01(const vector<int>& w, const vector<int>& v, int C){
        int n = w.size();
        memo = vector<vector<int>>(n, vector<int>(C+1, -1));
        return bestValue(w, v, n-1, C);
    }

};
