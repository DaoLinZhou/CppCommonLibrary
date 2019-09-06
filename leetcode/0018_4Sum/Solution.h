//
// Created by Daolin on 2019/9/4.
//
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0 && nums[i] > target)
                break;
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            vector<vector<int>> vec = threeSum(nums,i+1 ,target - nums[i]);
            for(int j=0; j<vec.size(); j++) {
                if(!vec[j].empty()) {
                    vec[j].push_back(nums[i]);
                    ret.push_back(vec[j]);
                }
            }
        }
        return ret;
    }

private:
    vector<vector<int>> threeSum(vector<int>& nums,int startIndex, int target) {
        if(nums.size()-startIndex<3)
            return {};
        vector<vector<int>> ret;
        for(int i = startIndex; i < nums.size(); i++){
            if(nums[i] > 0 && nums[i] > target)
                break;
            if(i > startIndex && nums[i-1] == nums[i])
                continue;
            int l = i+1, r = nums.size()-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    // 跳过所有相同的结果
                    int lvalue = nums[l], rvalue = nums[r];
                    while (l < r && nums[l] == lvalue) l++;
                    while (l < r && nums[r] == rvalue) r--;
                }
            }
        }
        return ret;
    }
};
