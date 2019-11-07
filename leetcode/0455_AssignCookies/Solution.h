//
// Created by Daolin on 2019/11/6.
//

#include "../commonHeader.h"

// 贪心算法

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for(int i = g.size()-1, index = s.size()-1; i >= 0 && index >= 0; i--){
            if(s[index] >= g[i]){
                res ++;
                index --;
            }
        }
        return res;
    }
};
