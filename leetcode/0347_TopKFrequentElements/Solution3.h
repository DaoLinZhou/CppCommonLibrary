//
// Created by Daolin on 2019/9/17.
//
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/**
 * 整合1,2 两种解, Solution1 是O(nlogk) 级别
 *               Solution2 是O(nlog(n-k)) 级别,
 *               所以当k更大时使用Solution2
 *               当k更小时使用Solution1
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // assert(k > 0);
        vector<int> ret;
        unordered_map<int, int> map;
        for(int i : nums)
            map[i] ++;

        if(k > map.size()/2)
            useMinHeap(map, ret, k);
        else
            useMaxHeap(map, ret, k);


        return ret;
    }

private:
    void useMinHeap(unordered_map<int, int>& map, vector<int>& ret, int k){
        priority_queue<pair<int, int>> pq;
        for(pair<int, int> item : map){
            pq.push({item.second, item.first});
            if(pq.size() > map.size() - k){
                ret.push_back(pq.top().second);
                pq.pop();
            }
        }
    }

    void useMaxHeap(unordered_map<int, int>& map, vector<int>& ret, int k){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(pair<int, int> item : map){
            if(pq.size() < k)
                pq.push(make_pair(item.second, item.first));
            else if(item.second > pq.top().first){
                pq.pop();
                pq.push(make_pair(item.second, item.first));
            }
        }
        while(!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
    }

};
