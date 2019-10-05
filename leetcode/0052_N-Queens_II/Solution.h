//
// Created by Daolin on 2019/10/3.
//

#include "../commonHeader.h"

class Solution {
private:
    int res;
    vector<bool> col, dia1, dia2;

    void putQueen(int n, int index){
        if(index == n){
            res ++;
            return;
        }

        for(int i = 0; i < n; i++){
            if(!col[i] && !dia1[i+index] && !dia2[index-i+n-1]){
                col[i] = true;
                dia1[i+index] = true;
                dia2[index-i+n-1] = true;
                putQueen(n, index+1);
                col[i] = false;
                dia1[i+index] = false;
                dia2[index-i+n-1] = false;
            }
        }
    }

public:
    int totalNQueens(int n) {
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n-1, false);
        dia2 = vector<bool>(2*n-1, false);

        putQueen(n, 0);
        return res;
    }
};
