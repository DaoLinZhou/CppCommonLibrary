//
// Created by Daolin on 2019/9/26.
//

#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 解题思路:
 *
 * 使用map刨除重复的元素
 *
 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for(int i: nums)
            map[i] ++;
        vector<int> vec;
        vector<vector<int>> res;
        for(int i = 0; i <= nums.size(); i++){
            select(res, i, map.begin(), vec);
            vec.clear();
        }
        return res;
    }

private:

    unordered_map<int, int> map;

    // 从map中选取n个元素(可以重复), 从start开始
    void select(vector<vector<int>>& res, int n,
                unordered_map<int, int>::iterator start,
                vector<int>& vec){

        if(n == 0){
            res.push_back(vec);
            return;
        }
        for(auto iter = start; iter != map.end(); iter++){
            if(iter->second > 0){   // 如果当前还有剩余
                vec.push_back(iter->first);
                map[iter->first] --;
                select(res, n-1, iter, vec);
                map[iter->first] ++;
                vec.pop_back();
            }
        }
    }

};