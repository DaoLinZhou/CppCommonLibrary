//
// Created by Daolin on 2019/10/13.
//
#include "../commonHeader.h"

class Solution {
public:
    int balancedStringSplit(string s) {
        int sum = 0, ans = 0;
        for (char c: s) {
            if (c == 'L') sum++;
            else sum--;
            if (sum == 0) ans++;
        }
        return ans;
    }
};
