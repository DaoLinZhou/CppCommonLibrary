//
// Created by Daolin on 2019/10/14.
//

#include "../commonHeader.h"

class Knapsack01{
private:

public:
    int knapsack01(const vector<int>& w, const vector<int>& v, int C){
        assert(w.size() == v.size());

        int n = w.size();

        if(n == 0 || C == 0)
            return 0;

        vector<int> memo(C+1, -1);
        /// 初始化第一行
        for( int j = 0; j <= C; j++)
            memo[j] = (j >= w[0] ? v[0] : 0);
        for(int i = 1; i < n; i++)
            for(int j = C; j >= w[i]; j--)
                memo[j] = max(memo[j],v[i] + memo[j-w[i]]);
        return memo[C];
    }

};

