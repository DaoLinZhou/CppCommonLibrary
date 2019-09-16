//
// Created by Daolin on 2019/9/15.
//
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/**
 * 解题思路: BFS 广度优先遍历
 * 从beginWord开始, 把下一步(只有一个字符不同)的string放入队列
 * 直到走到endWord
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> queue;
        unordered_set<string> set(wordList.begin(), wordList.end());    // 记录还没有遍历的字符串

        if(set.find(endWord) == set.end())      // 如果不包含
            return 0;

        queue.push(make_pair(beginWord, 1));    // beginWord算作一步
        set.erase(beginWord);                   // 不需要让beginWord走向自己
        while(!queue.empty()){
            string str = queue.front().first;
            int step = queue.front().second;
            queue.pop();

            if(str == endWord)                  // 找到了
                return step;

            // 尝试替换每一项, 假设字符串长度为s, 复杂度即为O(26s) 即O(s)
            // 相比于遍历wordList寻找只有一个不同的字符串 O(n), 在大数据量下, 复杂度降低不少
            for(int i = 0; i < str.size(); i++){
                string tmp = str;
                for(int j = 0; j < 26; j++){
                    tmp[i] = 'a' + j;
                    // 如果存在, 则放入队列, 同时从set中删除
                    if(set.find(tmp) != set.end()){
                        queue.push(make_pair(tmp, step + 1));
                        set.erase(tmp);
                    }
                }
            }
        }
        return 0;
    }

};
