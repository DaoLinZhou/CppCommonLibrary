//
// Created by Daolin on 2019/11/9.
//

#include "../commonHeader.h"

bool compare(const vector<int>& a, const vector<int>& b){
    if(a.back() != b.back())
        return a.back() < b.back();
    return a.front() < b.front();
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int res = 1;
        int pre = 0;
        for(int i = 1; i < intervals.size(); i++)
            if(intervals[i].front() >= intervals[pre].back()){
                res++;
                pre = i;
            }
         return intervals.size() - res;
    }
};
