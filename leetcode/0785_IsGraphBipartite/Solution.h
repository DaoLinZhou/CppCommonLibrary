//
// Created by Daolin on 2020/8/29.
//

#ifndef ALGORITHM_SOLUTION_H
#define ALGORITHM_SOLUTION_H

#include "../commonHeader.h"

class Solution {
public:

    bool bipartite = true;
    vector<int> color;

    bool isBipartite(vector<vector<int>>& graph){

        color = vector<int>(graph.size(), -1);

        for(int v = 0; v < graph.size(); v++){
            if(!bipartite) break;
            if(color[v] == -1){
                color[v] = 0;
                dfs(graph, v);
            }
        }
        return bipartite;
    }

    void dfs(vector<vector<int>>& graph, int v){
        for(int w: graph[v]){
            if(color[w] == -1){
                color[w] = 1-color[v];
                dfs(graph, w);
            }else if(color[w] == color[v]){
                bipartite = false;
                return;
            }
        }
    }
};


#endif //ALGORITHM_SOLUTION_H
