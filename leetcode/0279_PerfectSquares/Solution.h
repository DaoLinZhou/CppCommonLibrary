//
// Created by Daolin on 2019/9/15.
//
#include <queue>
#include <stdexcept>

using namespace std;

/**
 * 这道题本质上是求一个无权图的最短路径
 * 然而我们并不需要真正建立一个无权图,
 * 因为每个节点到与它相邻的节点都是有数学上的关系的
 *
 * 解题思路:
 * 通过queue进行广度优先遍历, 同时记录层次,
 * 直到到达0
 *
 */

class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> queue;
        queue.push(pair(n, 0));

        // 处理冗余, 如果a,b都可以通过d走向0
        // 假设a先走到d, 那么a到d到0一定比b到d到0短,
        // 所以我们只处理第一次访问的节点
        // 从 0 到 n, 有n+1个数据
        vector<bool> visited(n+1, false);
        visited[n] = true;

        while(!queue.empty()){
            int num = queue.front().first;
            int step = queue.front().second;
            queue.pop();
            for(int i = 1; ; i++){
                int a = num - i*i;  // 进行优化, 避免重复计算
                if(a < 0)           // 终止条件写在里面
                    break;
                if(a == 0)          // 到达 0
                    return step+1;
                if ( !visited[a] ){ // 只有没被访问过时才推入队列
                    queue.push(pair(a, step + 1));
                    visited[a] = true; // 标记为已访问
                }
            }
        }
        throw invalid_argument("No solution");
    }
};
