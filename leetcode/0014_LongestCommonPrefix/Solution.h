//
// Created by Daolin on 2019/11/23.
//

#include "../commonHeader.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        int len = strs[0].size();
        for (auto &str : strs)
            if(str.size() < len)
                len = str.size();
        string ret;
        for(int i = 0; i < len; i++){
            for(int j = 1; j < strs.size(); j++)
                if(strs[j][i] != strs[j-1][i])
                    return ret;
            ret += strs[0][i];
        }
        return ret;
    }
};
