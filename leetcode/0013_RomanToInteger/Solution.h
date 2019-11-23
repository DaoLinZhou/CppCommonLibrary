//
// Created by Daolin on 2019/11/17.
//
#include "../commonHeader.h"

class Solution {
public:

    int romanToValue(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: ; break;
        }
        return 0;
    }

    int romanToInt(string s) {
        int res = 0;
        for(int i = 1; i < s.size(); i++) {
            int n = romanToValue(s[i - 1]);
            if (romanToValue(s[i]) <= n)
                res += n;
            else
                res -= n;
        }
        res += romanToValue(s.back());
        return res;
    }
};
