//
// Created by Daolin on 2019/9/26.
//
#include <vector>

using namespace std;
/**
 * 解题思路:
 * 每次记录现在的位置i, 从[i...n] 中选取元素放入vec中
 * 当vec满了的时候就放入res中
 *
 */

class Solution {
private:
    vector<vector<int>> res = {};
    int n, k; // 设置为全局变量, 不用一次又一次地传参到方法

    // i是起始位置, 把[i...n]的所有可能放入vec中
    void combineHelper(int i, vector<int>& vec){
        if(k == vec.size()){
            res.push_back(vec);
            return;
        }
        // 不考虑i之前的元素, 防止重复
//        for(; i <= n; i++){
        // 优化, 剪枝, 我们要确保剩余的元素>=我们想要的元素
        // 剩余元素 n-i+1, 我们想要的元素 k - vec.size()
        // n-i+1 >= k - vec.size(), 通过数学变换可以得到
        // i <= n+1-(k - vec.size())
        for(; i <= n - (k - vec.size()) + 1; i++){
            vec.push_back(i);
            combineHelper(i + 1, vec);
            vec.pop_back();
        }

    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        this->n = n;
        this->k = k;
        combineHelper(1, vec);
        return res;
    }
};
