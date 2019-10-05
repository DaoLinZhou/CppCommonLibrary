//
// Created by Daolin on 2019/10/4.
//

/**
 * 递归解法
 */
class Solution {
public:
    int fib(int n) {
        if(n < 2)   /// n == 0 时返回0, n == 1时返回1
            return n;
        return fib(n-1) + fib(n-2);
    }
};
