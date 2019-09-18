//
// Created by Daolin on 2019/9/16.
//
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;

/**
 * 解题思路:
 *
 * 维护k个频次最高的元素
 *
 * 把所有元素放入map中, 记录出现次数, 通过最小堆进行比较次数,
 * 如果出现比最小堆中对顶次数更大的元素, 则添加
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // assert(k > 0);

        unordered_map<int, int> map;
        for(int i : nums)
            map[i] ++;
        // assert(k <= map.size());

        // c++中优先队列通过比较pair的first进行建堆, 所以first应该是出现的次数, second应该是出现的数字
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(pair<int, int> item : map){
            if(pq.size() < k)
                pq.push(make_pair(item.second, item.first));
            else if(item.second > pq.top().first){
                pq.pop();
                pq.push(make_pair(item.second, item.first));
            }
        }

        vector<int> ret;
        while(!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
