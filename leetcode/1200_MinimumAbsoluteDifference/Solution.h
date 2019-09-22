//
// Created by Daolin on 2019/9/21.
//
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 解题思路:
 * 分两步:
 *      1. 找到最小的差值
 *      2. 找到所有符合最小差值的数据对
 * 因此sort一下数组是一种很合理的想法
 */

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        if(arr.size() < 2)
            return {arr};
        vector<vector<int>> ret;
        sort(arr.begin(), arr.end());
        int abs = getMinAbsDif(arr);
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] == abs)
                ret.push_back({arr[i-1], arr[i]});
        }
        return ret;
    }

private:
    int getMinAbsDif(vector<int>& vec){
        int minabs = vec[1] - vec[0];
        for(int i = 2; i < vec.size(); i++){
            if(vec[i] - vec[i-1] < minabs)
                minabs = vec[i] - vec[i-1];
        }
        return minabs;
    }
};
