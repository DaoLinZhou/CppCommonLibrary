//
// Created by Daolin on 2019/11/17.
//
#include "../commonHeader.h"

class Solution {
public:
    int reverse(int x) {
        /// 如果x为最小int, -x会溢出
        if(x == INT32_MIN)
            return 0;
        if(x < 0)
            return -reverse(-x);
        int res = 0;
        int overflow = INT32_MAX/10;
        while(x != 0){
            /// 处理溢出
            if(res > overflow)
                return 0;
            res = res * 10 + x%10;
            x /= 10;
        }
        /// 如果没有溢出就返回res
        return res <= INT32_MAX ? res : 0;
    }
};
