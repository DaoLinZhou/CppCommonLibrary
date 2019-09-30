//
// Created by Daolin on 2019/9/29.
//
#include "../commonHeader.h"

/**
 * 解题思路:
 *
 * 使用map记录所有元素出现次数
 * 再把所有次数导出到vector并排序
 * 遍历如果有两个相同的挨在一起就返回false
 * 没有相同的就返回true
 *
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i: arr)
            map[i] ++;
        vector<int> vec;
        for(auto combo : map)
            vec.push_back(combo.second);
        sort(vec.begin(), vec.end());
        for(int i = 1; i < vec.size(); i++){
            if(vec[i] == vec[i-1])
                return false;
        }
        return true;
    }
};
