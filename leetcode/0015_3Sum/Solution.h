//
// Created by Daolin on 2019/9/4.
//
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Combo{
private:
    vector<int> data;
public:
    Combo(vector<int> data):data(data){
    }

    vector<int> getData(){
        return data;
    }

    string toString(){
        return ""+data[0] + data[1] + data[2];
    }

};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<string, bool> flag1;
        unordered_map<int, int> flag2;
        vector<vector<int>> ret;
        int i=0;
        while(i < nums.size() && nums[i] <= 0){
            for(int j = i+1; j < nums.size() && nums[j] <= -nums[i] ; j++){
                int target = 0 - nums[i] - nums[j];
                if(flag2.find(target) != flag2.end() || binarySearch(nums, target, j+1, nums.size()-1)){
                    flag2[target] ++;
                    Combo combo({nums[i], nums[j], target});
                    if(flag1.find(combo.toString()) == flag1.end()) {
                        ret.push_back(combo.getData());
                        flag1[combo.toString()] = true;
                    }
                }
            }
            i++;
        }
        return ret;
    }

private:
    bool binarySearch(vector<int>& vec, int target, int si, int ei){
        int l = si, r = ei;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(vec[mid] == target)
                return true;
            else if(vec[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};
