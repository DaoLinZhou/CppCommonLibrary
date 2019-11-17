//
// Created by Daolin on 2019/11/17.
//
#include "../commonHeader.h"

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& A, int k) {
        int n = A.size();
        int m = A[0].size();

        vector < int > all;
        for(int i = 0;i < n;++i) {
            for(int j = 0;j < m;++j) {
                all.push_back(A[i][j]);
            }
        }
        k %= all.size();


        int idx = 0;
        for(int i = (k/m);i < n;++i) {
            for(int j = (i == (k/m) ? (k%m) : 0);j < m;++j) {
                A[i][j] = all[idx++];
            }
        }

        for(int i = 0;i < n;++i) {
            for(int j = 0;j < m;++j) {
                if(idx == all.size()) {
                    return A;
                }
                A[i][j] = all[idx++];
            }
        }
        return A;
    }
};
