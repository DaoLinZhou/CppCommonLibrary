//
// Created by Daolin on 2019/9/6.
//

#include <vector>
#include <unordered_map>

using namespace std;
/**
 * 解题思想:
 * 遍历数组, 取标定点 i
 *
 * 再遍历数组, 存储所有点到i的距离到 map中, key是距离, value是点的个数
 * 遍历map 如果点的个数大于等于2, 就说明有至少两个点到i的距离相同
 * 通过乘法原理计算有几种可能
 */

// Time complexity O(n^2)
// Space complexity O(n)
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<int, int> record;
            // 把所有其他点对点i的距离都记录到record中
            for(int j = 0; j < points.size(); j++)
                if(j != i)
                    // 记录 (距离,点数) 这个键值对
                    record[dis(points[i], points[j])] ++;

            for(unordered_map<int, int>::iterator iter = record.begin();
                    iter != record.end(); iter++){
                // 如果记录的值大于等于2, 就说明至少有两个点到i的距离相同
//                if(iter->second >= 2)     不进行判断也是可以的, 因为当小于2时, 这两个值中一定有一个为0
                    res += iter->second * (iter->second-1);
            }
        }
        return res;
    }

private:
    // 返回值要注意整型越界, 本题给定范围[-10000, 10000]不会越界
    // 但若要再大一点就可能会越界, 根据具体数字决定返回值是long 还是long long
    int dis(vector<int>& p1, vector<int>& p2){
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};
