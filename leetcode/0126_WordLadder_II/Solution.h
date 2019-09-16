//
// Created by Daolin on 2019/9/15.
//
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * 耗时3个半小时, 终于搞出来了
 */

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> map;     // 记录所有string, 以及他们出现的level

        // 记录是否被访问过, 例如当a->c, b->c 时, 如果不进行判断会向队列中push 2个c, 而我们要避免这种情况
        unordered_set<string> visited;

        // 初始化
        for(const string &str : wordList)
            map[str] = 0;

        // 如果没有元素
        if(!map.count(endWord))
            return {};
        map.erase(beginWord);

        // 当走到最后时用于反向查找, second记录first的所有父亲节点
        unordered_map<string, vector<string>> backFinding;

        // 队列, 用于广度优先遍历
        queue<pair<string, int>> queue;
        queue.push(make_pair(beginWord, 1));
        int maxLevel = 0;   // 用于反向查找的循环
        while(!queue.empty()){
            string cur = queue.front().first;
            int level = queue.front().second;
            queue.pop();

            if(cur == endWord) {        // 第一次找到就退出, 因为已经记录所有的endWord的父亲节点
                maxLevel = level;
                break;
            }

            // 尝试所有只变化一种字节的可能
            for(int i = 0; i < cur.length(); i++){
                string tmp = cur;
                for(int j = 'a'; j <= 'z'; j++){
                    tmp[i] = j;

                    // 如果不存在, 接着找
                    if(map.find(tmp) == map.end()){
                        continue;
                    } else if(map[tmp] == 0 || map[tmp] == level + 1) {
                        // 如果第一次访问tmp 或者 相同level下访问tmp
                        map[tmp] = level + 1;       // 更新到达tmp的最小level
                        if(!visited.count(tmp)) {   // 如果访问过就不在放入队列中, 确保队列中只有一个tmp
                            queue.push(make_pair(tmp, level + 1));
                            visited.insert(tmp);
                        }
                        // 更新tmp的父亲节点
                        backFinding[tmp].push_back(cur);
                    } else if(map[tmp] < level + 1){
                        // 当层数更大的str变化为tmp时, 说明所有最短到达tmp的已经遍历过了, 所以我们不在需要tmp了
                        map.erase(tmp);
                    }
                }
            }
        }

        // 可能没有解, 即endWord没有父亲节点
        if(backFinding[endWord].empty())
            return {};

        // 用于返回
        vector<vector<string>> ret;
        ret.push_back({endWord});   // 从endWord开始反向推导

        // 因为在下面的循环中, 会不断向ret中push新的vector,所以ret的长度是变化的
        int retSize = ret.size();

        // 最多走maxLevel层, 而我们已经走完一层, 即endWord
        for(int i = 1; i < maxLevel; i++){

            // 每次遍历ret中所有的vec, 将所有vec向前倒推一位
            for(int j = 0; j < retSize; j++){
                // 记录这个vec的最后一个str, 即我们要倒推的str
                string last = ret[j][ret[j].size()-1];

                // 如果到达起始点, 说明这个vec已经推导完成, 继续下一个推导
                if(last == beginWord)
                    continue;

                // 如果父亲只有一个元素
                if(backFinding[last].size() == 1){
                    ret[j].push_back(backFinding[last][0]);
                }else{      // 如果父亲有多个元素, 即走向岔路口
                    // 记录要新push几个数组到ret末尾
                    int newVecNum = backFinding[last].size()-1;
                    // 记录当前的 retSize, 用于后面循环push使用
                    int retSizeTmp = ret.size();
                    // 复制newVecNum个ret[j]到ret末尾
                    copyAndPush(ret, ret[j], newVecNum);
                    retSize += newVecNum;   // retSize增加

                    // 当前vec的向前倒推一位父节点
                    ret[j].push_back(backFinding[last][0]);
                    // 从 retSizeTmp 到 retSizeTmp+newVecNum-1 是新增的vec的位置
                    for(int k = 0; k < newVecNum; k++)
                        // 向每一个vec中放入一个不同的父节点
                        ret[retSizeTmp + k].push_back(backFinding[last][k + 1]);
                }
            }
        }

        // 注意由于是倒推所以是倒序, 所以要把每一个vec反转一下成为正序
        for (auto &i : ret)
            reverse(i.begin(), i.end());

        return ret;


    }

private:
    void copyAndPush(vector<vector<string>>& ret, vector<string> vec, int n){
        for(int i = 0; i < n; i++)
            ret.push_back(vec);
    }
};