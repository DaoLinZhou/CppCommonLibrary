//
// Created by Daolin on 2019/10/5.
//
#include "../commonHeader.h"

/**
 * 超时的解, 但接下来要对这个解进行优化, 让它不在超时
 */

class Solution {
private:
    int minimumPath(vector<vector<int>>& triangle, int index, int level){
        if(level == triangle.size())
            return 0;

        return triangle[level][index] + min(minimumPath(triangle, index, level+1),
                                            minimumPath(triangle, index+1, level+1));
    }


public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return minimumPath(triangle, 0, 0);
    }
};
