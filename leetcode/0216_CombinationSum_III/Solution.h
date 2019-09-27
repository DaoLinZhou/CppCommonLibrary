//
// Created by Daolin on 2019/9/26.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        combineHelper(k, n, 1, vec);
        return res;
    }

private:
    vector<vector<int>> res;

    // find k number which sum is target, from [start...9]
    void combineHelper(int k, int target, int start, vector<int>& vec){
        if(target==0 && k == 0){
            res.push_back(vec);
            return;
        }

        // k没有了
        if(k <= 0)
            return;

        // 递归查找, 优化: i <= target
        for(int i = start; i <= 9 && i <= target; i++){
            vec.push_back(i);
            combineHelper(k - 1, target - i, i + 1, vec);
            vec.pop_back();
        }
    }
};