
//
// Created by Daolin on 2019/9/29.
//

#include "../commonHeader.h"

/**
 * 解题思路:
 *
 * 首先很明显这道题是一个递归问题
 * 没找到连续k个一样的, 就把它删除, 剩余的子数组继续递归
 * 如果字符串小于k个, 或者找不到k个连续的, 就返回
 *
 */

class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size() < k)
            return s;
        int map[26] = {0};
        for(int i = 0; i < k; i++)
            map[s[i] - 'a'] ++;
        // [i-k, i-1]
        for(int i = k; i <= s.size(); i++){
            if(isUnique(map, k)){
                // 切除 [i-k, i-1] 这部分, 递归查找
                string sub = s.substr(0, i-k) + s.substr(i);
                return removeDuplicates(sub, k);
            }else if(i < s.size()){
                // 滑动窗口
                map[s[i] - 'a'] ++;
                map[s[i-k] - 'a'] --;
            }
        }
        return s;
    }

private:
    // 判断滑动窗口中是否只有一个种类的元素
    bool isUnique(int map[], int k){
        for(int i = 0; i < 26; i++)
            if(map[i] != k && map[i] != 0)
                return false;
        return true;
    }
};
