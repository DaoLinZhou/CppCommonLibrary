//
// Created by Daolin on 2019/10/5.
//
#include "../commonHeader.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /// 如果只有一层, 直接返回
        if(triangle.size() == 1)
            return triangle[0][0];
        /// i 代表层数, j代表元素在当前层的位置
        for(int i = triangle.size()-2; i >= 0; i--)
            for(int j = 0; j < triangle[i].size(); j++)
                /// 当前位置的最小路径, 是当前位置的值, 加上最小左右路径的值
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
        /// 全部推导完成后, 顶点的值就是路径的值
        return triangle[0][0];
    }
};
