//
// Created by Daolin on 2019/10/7.
//
#include "../commonHeader.h"

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0, even = 0;
        for(int i = 0; i < chips.size(); i++)
            (chips[i] % 2 == 1) ? odd++ : even++;
        return min(odd, even);
    }
};
