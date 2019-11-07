//
// Created by Daolin on 2019/11/6.
//

#include "../commonHeader.h"

static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty())
            return true;

        int si = 0;
        for(int ti = 0; ti < t.size(); ti++){
            if(s[si] == t[ti])
                si++;
            if(si == s.size())
                return true;
        }
        return false;
    }
};
