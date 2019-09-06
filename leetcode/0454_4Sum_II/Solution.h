//
// Created by Daolin on 2019/9/5.
//
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


/**
 * 解题思路:
 * 如果使用暴力解法, 4个循环, 当 a+b+c+d == 0 时记录, 时间复杂度是 O(n^4)
 * 一个自然的想法就是先把 A 中所有数放入map中, 循环 B,C,D, 判断 0-(b+c+d) 是否在 map中,
 * 这样时间复杂度就是 O(n^3 + n) = O(n^3)
 * 更进一步, 把 A, B中所有组合都放入map, 之后再循环 C,D, 判断 0-(c+d) 是否在 map中,
 * 时间复杂度是 O(n^2 + n^2) = O(n^2)
 *
 * 仔细观察这三个思路的时间复杂度 O(n^4), O(n + n^3), O(n^2 + n^2)
 * 就像是把4分到两个n的指数上
 * 能否根据这个思路继续优化呢 ?  不行, 因为如果把ABC的所有组合放入map会是 n^3 复杂度, 退化到第二种情况
 */
class Solution{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int> D){
        unordered_map<int,int> count;
        int ret = 0;
        for(int a : A)
            for(int b : B)
                count[a+b] ++;
        for(int c : C)
            for(int d : D){
                auto item = count.find(0-c-d);
                if(item != count.end())
                    ret += item->second;
            }
        return ret;
    }
};
