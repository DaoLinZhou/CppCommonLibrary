//
// Created by Daolin on 2019/9/26.
//

#include <vector>
#include <algorithm>

using namespace std;

/**
 * 解题思路:
 * 排序后递归求解, 为什么排序? 为了提前终止, 如果i大于target, 那么i后面的有数都大于target, 就不用考虑了
 */

class Solution {
private:
    vector<vector<int>> res;
    void combineHelper(vector<int>& candidates,int start , int target, vector<int>& vec){
        if(target == 0 || start == candidates.size()){
            res.push_back(vec);
            return;
        }else{
            for(int i = start; i < candidates.size(); i++){
                if(target < candidates[i])  // i后面的都比target大
                    break;
                vec.push_back(candidates[i]);
                // 从i向后递归寻找
                combineHelper(candidates, i, target - candidates[i], vec);
                vec.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> vec = {};
        combineHelper(candidates, 0, target, vec);
        return res;
    }
};