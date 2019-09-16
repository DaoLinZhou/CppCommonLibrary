//
// Created by Daolin on 2019/9/15.
//

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * 神仙解法:
 * 不是自己写的, 但我想分析一下它为什么执行这么快
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        int l = beginWord.length();

        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};

        int step = 0;

        while (!q1.empty() && !q2.empty()) {
            ++step;

            // Always expend the smaller queue first
            if (q1.size() > q2.size())
                std::swap(q1, q2);

            unordered_set<string> q;

            for (string w : q1) {
                for (int i = 0; i < l; i++) {
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if (q2.count(w)) return step + 1;
                        if (!dict.count(w)) continue;
                        dict.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }

            std::swap(q, q1);
        }

        return 0;
    }
};


