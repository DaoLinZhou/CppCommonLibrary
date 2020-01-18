//
// Created by Daolin on 2020/1/17.
//

#include "../commonHeader.h"

class Solution {
public:
    int r, c;

    bool getSum(vector<vector<int>>& mat, const int& side, int x, int y, int threshold){
        for(int i = 0; i < side; i++)
            for(int j = 0; j < side; j++) {
                threshold -= mat[i + x][j + y];
                if(threshold < 0)
                    return false;
            }
        return true;
    }

    bool find(vector<vector<int>>& mat, const int& threshold, const int& side){
        for(int i = 0; i < r-side+1; i++)
            for(int j = 0; j < c-side+1; j++)
                if(getSum(mat, side, i, j, threshold))
                    return true;
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        r = mat.size();
        c = mat[0].size();
        int maxSide = min(r, c);

        int count = 0;
        for(int i = 1; i <= maxSide; i++, count ++)
            if(!find(mat, threshold, i))
                return count;
        return maxSide;
    }
};
