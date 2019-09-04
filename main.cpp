#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

class Answer{
private:
    vector<int> data;

public:
    Answer(vector<int> vec){
        sort(vec.begin(), vec.end());
        data = vec;
    }

    vector<int> getData(){
        return data;
    }

    bool operator ==(Answer ans){
        for(int i=0; i < 3; i++)
            if(ans.data[i] != data[i])
                return false;
        return true;
    }

    bool operator >(Answer ans){
        for(int i=0; i < 3; i++)
            if(ans.data[i] != data[i])
                return data[i] > ans.data[i];
        return false;
    }

    bool operator<(Answer ans){
        for(int i=0; i < 3; i++)
            if(ans.data[i] != data[i])
                return data[i] < ans.data[i];
        return false;
    }

    string toString(){
        string s = "";
        for(int i=0; i < 3; i++)
            s += data[i];
        return s;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        vector<vector<int>> ret;
        unordered_map<string, bool> record;
        unordered_map<int, bool> count;
        for(int i=0; i<nums.size()-2; i++){
            if(count.find(nums[i]) != count.end())
                continue;
            count[nums[i]] = true;
            int target = 0 - nums[i];
            vector<vector<int>> combo = twoSum(nums, target, i);
            for(int j=0; j<combo.size(); j++){
                if(!combo[j].empty()){
//                    cout << nums[i] <<" : "<< nums[combo[j][0]] << " : " << nums[combo[j][1]] << endl;
                    Answer item({nums[i], nums[combo[j][0]], nums[combo[j][1]]});
                    if(record.find(item.toString()) == record.end()){
                        ret.push_back(item.getData());
                        record[item.toString()] = true;
                    }
                }
            }
        }
        return ret;
    }

private:
    vector<vector<int>> twoSum(vector<int>& nums, int target, int index) {
        vector<vector<int>> ret;
        unordered_map<int, int> record;
        for(int i = index+1; i < nums.size(); i++){
            if(record.find(nums[i]) != record.end()){
                ret.push_back({record[nums[i]], i});
            }else{
                record[target-nums[i]] = i;
            }
        }
        return ret;
    }
};


int main(){


    return 0;
}


