//
// Created by Daolin on 2019/9/26.
//

#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * 解题思路:
 *
 * 由于不需要对重复元素进行求解, 所以使用map过滤相同元素
 * 使用map判断是否使用过某些元素, 或者还可以使用哪些元素.
 *
 * 由于使用map, 所以递归的start索引使用 map<int, int>::iterator类型
 *
 * 使用map的顺序性来提前终止, 因此使用map而非unordered_map
 *
 * 最后感叹一句: 画图思考真的很有用, 有时候甚至能帮你直接想出最优解
 *
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(int i : candidates)
            myMap[i] ++;
        vector<int> vec = {};
        combineHelper(candidates, myMap.begin(),target, vec);
        return res;
    }

private:
    vector<vector<int>> res;
    map<int, int> myMap;
    void combineHelper(vector<int>& candidates, map<int, int>::iterator start, int target, vector<int>& vec){
        if(target == 0){
            res.push_back(vec);
            return;
        }
        // 通过画出树形执行结构, 发现相同的值只调用一次即可, 所以使用map进行记录
        for(map<int, int>::iterator iter = start; iter != myMap.end(); iter++){
            if(iter->first > target)    // 利用map的顺序性, 因此没有使用unordered_map
                return;
            if(iter->second > 0){
                myMap[iter->first] --;
                vec.push_back(iter->first);

                combineHelper(candidates, iter ,target - iter->first, vec);

                myMap[iter->first] ++;
                vec.pop_back();
            }
        }

    }
};