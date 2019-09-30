//
// Created by Daolin on 2019/9/27.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:


    vector<string> readBinaryWatch(int num) {
        vector<int> hours = {1, 2, 4, 8};
        vector<int> minutes = {1, 2, 4, 8, 16, 32};

        // 通过数学知识, 我们可以得出num最大为8
        if(num > 8)
            return {};

        vector<string> answer;
        vector<string> hourRes;
        vector<string> minRes;
        for(int i = 0; i <= hours.size() && i <= num; i++){
            choose(hourRes, hours, i, true);
            choose(minRes, minutes, num - i, false);

            // 拼接所有组合
            for(string hour : hourRes)
                for(string min : minRes)
                    answer.push_back(hour + ":" + min);

            hourRes.clear();
            minRes.clear();
        }
        return answer;
    }


    // 把从nums中选取n个的所有可能放入realRes中
    void choose(vector<string>& realRes, vector<int>& nums, int n, bool isHour){
        if(n > nums.size())
            return;

        vector<vector<int>> res;
        vector<int> vec;
        choose(res, nums, n, 0, vec);

        for(auto& item : res){
            if(item.size() == 0){
                realRes.push_back(isHour ? "0" : "00");
            }else{
                string time;
                int sum = 0;
                for(int i : item)
                    sum += i;
                if((!isHour && sum < 60) || (isHour && sum < 12)){  // 确保范围合法
                    time = to_string(sum);
                    if(!isHour && time.size() == 1)
                        time = "0" + time;
                    realRes.push_back(time);
                }
            }
        }
    }

    void choose(vector<vector<int>>& res, vector<int>& nums, int n, int start, vector<int>& vec){
        if(n == 0){
            res.push_back(vec);
            return;
        }
        for(int i = start; i+n-1 < nums.size(); i++){
            vec.push_back(nums[i]);
            choose(res, nums, n - 1, i + 1, vec);
            vec.pop_back();
        }
    }


};