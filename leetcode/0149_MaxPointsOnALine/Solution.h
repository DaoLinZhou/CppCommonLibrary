//
// Created by Daolin on 2019/9/6.
//
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 解题思想:
 * 遍历所有点, 记录每个点和点 i 组成的 slope 值(由于double精度问题, 以string类型存储最简分子和分母)
 * 记录最大的slope
 * 陷阱1: slope的公式是 dy/dx 但如果 dx 为 0时, gcd会出现错误
 * 陷阱2: 当有点重合时, 应该记录重合了多少个点
 * 陷阱3: 当所有点重合时, 不会遍历map, 所以此时应该直接返回size()的值, 因为所有点重合在一起, 所以所有点都在一条线上
 *
 */

// 求最大公约数
int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2)
            return points.size();
        int res = 0;

        unordered_map<string, int> record;
        for(int i = 0; i < points.size(); i++){
            int sameNumCount = 1;   // 自己本身也与自己重合
            for(int j=i+1; j<points.size(); j++){
                if(i == j)  // 跳过自己
                    continue;
                // 当点重合时
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                    sameNumCount ++;
                    continue;
                }
                // 记录同一个slope有几个点
                string slope = countSlop(points[i], points[j]);
                record[slope] ++;
            }
            // 遍历查找每个slop包含几个点
            for(auto num : record)
                if(num.second + sameNumCount > res)
                    res = num.second + sameNumCount;
            // 当所有点重合时, 如果有一个点不重合都至少有一个slope
            if(res == 0)
                return points.size();
            // 清空查找表
            record.clear();
        }
        return res;
    }

private:
    // 以 分子/分母 的字符串形式存储slop
    string countSlop(vector<int>& p1, vector<int>& p2){
        int dx = p1[0] - p2[0];
        int dy = p1[1]-p2[1];
        if(dx == 0)
            return "inf";
        int cd = gcd(dx, dy);
        return to_string(dy/cd)+"/"+to_string(dx/cd);
    }
};
