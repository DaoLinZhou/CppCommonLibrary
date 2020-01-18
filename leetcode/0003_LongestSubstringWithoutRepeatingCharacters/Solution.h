//
// Created by Daolin on 2019/12/3.
//
#include "../commonHeader.h"

class Solution {
public:
    /// subset scope [l...r]
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = -1, ret = 0;
        int count[128] = {0};
        while(l < s.size()){
            if(r+1 < s.size() && count[s[r+1]] == 0){
                count[s[++r]] ++;
            }else{
                count[s[l++]] --;
            }
            ret = max(ret, r-l+1);
        }
        return ret;
    }
};
