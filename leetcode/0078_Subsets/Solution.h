//
// Created by Daolin on 2019/9/26.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i = 0; i <= nums.size(); i++){
            vector<int> vec;
            select(nums, i, 0, res, vec);
        }
        return res;
    }

private:
    void select(vector<int>& nums, int n, int start, vector<vector<int>>& res, vector<int>& vec){
        if(n == 0 || start >= nums.size()){
            res.push_back(vec);
            return;
        }
        for(int i = start; i < nums.size() && (i + n-1) < nums.size(); i++){
            vec.push_back(nums[i]);
            select(nums, n - 1, i + 1, res, vec);
            vec.pop_back();
        }
    }
};
