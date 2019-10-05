//
// Created by Daolin on 2019/10/4.
//

/**
 *  循环解法
 */
class Solution {
public:
    int fib(int n) {
        /// n == 0 时返回0, n == 1时返回1
        if(n < 2)
            return n;

        int a = 0;
        int b = 1;

        int c;
        for(int i = 2; i <= n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};
