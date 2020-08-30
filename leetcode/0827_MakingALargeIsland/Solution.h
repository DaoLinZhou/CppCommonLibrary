//
// Created by Daolin on 2020/8/30.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "../commonHeader.h"

/**
 * 思路: 首先求出所有联通分量, 并记录每个联通分量内节点个数
 * 一块水域最多只能连接上下左右四个方向的土地, 所以对上下左右的联通分量求和再加1(注意可能有重复所以用set去重)
 * 例如上方可左方连接的是同一个联通分量, 所以只应该计算一次
 * 同时要考虑特殊情况: 如果没有水域, 那么结果就是岛屿的节点数
 */

class Solution {
private:
    int m, n, comp;
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        map<int, int> map;

        comp = 2;   // 记录联通分量的id
        for(int x = 0; x < m; x ++){
            for(int y = 0; y < n; y++){
                if(grid[x][y] == 1){
                    int num = floodFill(grid, x, y);
                    map[comp] = num;    // 记录联通分量和它的节点个数
                    comp++;
                }
            }
        }

        int res = 1;
        for(auto& p : map){     // res最少为目前最大岛屿的节点数量
            res = max(res, p.second);
        }

        for(int x = 0; x < m; x ++){
            for(int y = 0; y < n; y++){
                if(grid[x][y] == 0){
                    set<int> set;
                    int num = 1;
                    for(auto& i : d){   // 记录四周的岛屿的联通分量id
                        int newx = x+i[0];
                        int newy = y+i[1];
                        if(inArea(newx, newy) && grid[newx][newy] != 0){
                            set.insert(grid[newx][newy]);
                        }
                    }
                    for(int i : set){   // 对这些联通分量求和再加一
                        num += map[i];
                    }
                    res = max(res, num);
                }
            }
        }
        return res;
    }

    int floodFill(vector<vector<int>>& grid, int x, int y){
        int res = 1;
        grid[x][y] = comp;
        for(auto& i : d){
            int newx = x+i[0];
            int newy = y+i[1];
            if(inArea(newx, newy) && grid[newx][newy] == 1){
                res += floodFill(grid, newx, newy);
            }
        }
        return res;
    }

};


#endif //ALGORITHM_SOLUTION_H
