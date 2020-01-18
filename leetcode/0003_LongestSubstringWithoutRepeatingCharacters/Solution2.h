//
// Created by Daolin on 2019/12/3.
//
#include "../commonHeader.h"

class Solution {
public:
    /// subset scope [l...r)
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2)
            return s.size();

        int l = 0, r = 0, ret = 0;
        int count[128] = {0};
        while(r < s.size()){
            if(count[s[r]] == 0){
                count[s[r++]] ++;
            }else{
                count[s[l++]] --;
            }
            ret = max(ret, r-l);
        }
        return ret;
    }
};
