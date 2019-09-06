//
// Created by Daolin on 2019/9/5.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        for(int i = 0; i < nums.size(); i++){
            if(record.find(nums[i]) != record.end()){
                return {record[nums[i]], i};
            }else{
                record[target-nums[i]] = i;
            }
        }
        return {};
    }
};