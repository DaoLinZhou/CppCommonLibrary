//
// Created by Daolin on 2019/9/17.
//

#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;

/**
 * 解题思路:
 *
 * 维护n-k个频次最低的元素, 所有不在堆中的元素都是我们要的
 *
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> map;
        for(int i : nums)
            map[i] ++;

        priority_queue<pair<int, int>> pq;
        for(pair<int, int> item : map){
            pq.push({item.second, item.first});
            if(pq.size() > map.size() - k){
                ret.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ret;
    }
};
