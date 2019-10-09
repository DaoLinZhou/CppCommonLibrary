//
// Created by Daolin on 2019/10/8.
//
#include "../commonHeader.h"

/**
 * 使用数学的方式进行解题, 寻找m*n的路径
 * 解为(m-1 + n-1) choose (n-1)
 */

class Solution {
private:
    int choose(int x, int y){
        int z = x-y;
        unordered_set<int> set;

        for(int i = 2; i <= z; i++)
            set.insert(i);

        int res = 1;
        vector<int> tmp;
        for(int i = x; i > y; i--){
            res *= i;
            for(auto num : set)
                if(res % num == 0){
                    res /= num;
                    tmp.push_back(num);
                }
            for(auto item : tmp)
                set.erase(item);
            tmp.clear();
        }
        return res;
    }

public:
    int uniquePaths(int m, int n) {
        return choose(m+n-2, max(n-1, m-1));
    }
};
