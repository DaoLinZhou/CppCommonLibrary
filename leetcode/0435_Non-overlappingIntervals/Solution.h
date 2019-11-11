//
// Created by Daolin on 2019/11/9.
//

#include "../commonHeader.h"

bool compare(const vector<int>& a, const vector<int>& b){
    if(a.front() != b.front())
        return a.front() < b.front();
    return a.back() < b.back();
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        /// memo[i] 表示使用intervals[0...i]的区间能构成的最长不重叠序列
        vector<int> memo(intervals.size(), 1);
        for(int i = 1; i < intervals.size(); i++)
            // memo[i]
            for(int j = 0; j < i; j++)
                if(intervals[i].front() >= intervals[j].back())
                    memo[i] = max(memo[i], 1 + memo[j]);
        int res = *max_element(memo.begin(), memo.end());
        return intervals.size() - res;
    }
};
