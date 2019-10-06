//
// Created by Daolin on 2019/10/5.
//
#include "../commonHeader.h"


class Solution {
private:
    // 记录每个位置的答案
    vector<int> memo;

    int minimumPath(vector<vector<int>>& triangle, int index, int level){
        if(level == triangle.size())
            return 0;
        int memoIndex = level*(level+1)/2+index;;
        if(memo[memoIndex] == -1)
            memo[memoIndex] = triangle[level][index] + min(minimumPath(triangle, index, level+1),
                                                           minimumPath(triangle, index+1, level+1));
        return memo[memoIndex];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int total = (triangle.size()+1)*triangle.size()/2;
        memo = vector<int>(total, -1);
        return minimumPath(triangle, 0, 0);
    }
};
