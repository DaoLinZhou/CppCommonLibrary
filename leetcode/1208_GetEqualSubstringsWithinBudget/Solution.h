//
// Created by Daolin on 2019/9/29.
//
#include "../commonHeader.h"

/**
 * 解题思路:
 *
 * 首先求出所有的距离, 之后滑动窗口, 保持窗口的元素和小于等于maxCost
 * 求最大窗口大小
 *
 */

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> vec;
        for(int i=0; i<s.size(); i++)
            vec.push_back(abs(s[i] - t[i]));

        int maxdis = 0;
        int sum = 0;
        int l = 0, r = -1;
        /// 滑动窗口 [l...r]
        while (l < vec.size()) {
            if(sum <= maxCost)
                maxdis = max(r-l+1, maxdis);
            if (r + 1 < vec.size() && sum <= maxCost){
                sum += vec[++r];
            }else
                sum -= vec[l++];
        }
        return maxdis;
    }
};
