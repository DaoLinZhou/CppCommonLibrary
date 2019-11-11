//
// Created by Daolin on 2019/11/10.
//

#include "../commonHeader.h"

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(auto& combo : indices){
            int r = combo[0], c = combo[1];
            for(int i = 0; i < m; i++) matrix[r][i] ++;
            for(int i = 0; i < n; i++) matrix[i][c] ++;
        }
        int res = 0;
        for(auto& ele : matrix)
            for(int i = 0; i < ele.size(); i++)
                if(ele[i] % 2) res++;
        return res;
    }
};
