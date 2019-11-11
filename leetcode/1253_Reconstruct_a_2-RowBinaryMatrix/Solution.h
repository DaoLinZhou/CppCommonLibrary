//
// Created by Daolin on 2019/11/10.
//
#include "../commonHeader.h"

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int col = colsum.size();
        vector<vector<int>> m(2, vector<int>(col, 0));
        int sum = 0;
        int total = upper + lower;
        for(int i = 0; i < col; i++){
            sum += colsum[i];
            if(colsum[i] == 2){
                m[0][i] = m[1][i] = 1;
                upper --;
                lower --;
            }
        }
        if(total != sum || lower < 0 || upper < 0)
            return {};
        for(int i = 0; i < col; i++){
            if(colsum[i] == 1){
                if(upper > 0){
                    m[0][i] = 1;
                    upper --;
                }else if(lower > 0){
                    m[1][i] = 1;
                    lower --;
                }
            }
        }
        return m;
    }
};
