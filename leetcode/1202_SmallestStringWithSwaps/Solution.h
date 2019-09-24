//
// Created by Daolin on 2019/9/22.
//
#include <vector>
#include <string>
#include <algorithm>
#include "../../unionfind/UnionFind5.h"

using namespace std;

/**
 * 解题思路:
 *
 * 如果0-3可以互换, 3-4可以互换, 那么0-4也可以互换
 * 所以使用并查集可以快速判断两个位置是否可以互换
 *
 * 记录所有可以互换的位置, 取出这些位置的元素, 排序后再依次放回
 */

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UF5::UnionFind UF(n);

        for (vector<int> &p : pairs)
            UF.unionElements(p[0], p[1]);

        /// 记录所有可以互换的元素的位置
        /// 例如 1 ,3 位置的元素可以互换, 2, 4 可以互换, 则记录类似[[],[],[1,3], [2,4]]
        /// 最多有n组元素, 所以可能有空vector
        vector<vector<int>> components(n, vector<int>());

        /// 为components填充元素, components内的每一个数组都是有序的
        for (int i = 0; i < n; i++)
            components[UF.find(i)].push_back(i);

        string res;
        /// 我们要把components中每个数组记录的位置的char排序, 重新分配到s的对应位置上
        /// 例如: component存储1, 3, 5, 则我们首先要取出他们对应的元素, 假设为b, a, c
        /// 之后重新排列为 a,b,c, 最后把排好序的元素重新放回 1, 3, 5 的位置分别为(a,b,c)
        for (vector<int> &component : components) {
            string chars;

            // 拿出所有的char
            for (int index : component)
                chars += s[index];
            // 排序
            sort(chars.begin(), chars.end());
            // 重新放回s中, 对于的位置是component[i], 由于push的时候是顺序push的, 所以component是有序的
            for (int i = 0; i < (int) component.size(); i++)
                s[component[i]] = chars[i];
        }

        return s;
    }
};
