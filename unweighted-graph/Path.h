//
// Created by Daolin on 2019/8/17.
//

#ifndef ALGORITHM_PATH_H
#define ALGORITHM_PATH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

template <typename Graph>
class Path {
private:
    Graph &G;
    bool* visited;
    int s;      // 起始点
    int* from;  // 保存每个点的前一个点

    void dfs(int v){
        visited[v] = true;

        typename Graph::adjIterator adj(G, v);
        for(int i = adj.begin(); !adj.isEnd(); i = adj.next()){
            if(!visited[i]) {
                from[i] = v;    // 这里对from进行填充, i是和v有相邻边的节点, v是本节点, 所以可以从v走到i
                dfs(i);
            }
        }
    }

public:
    Path(Graph &graph, int s):G(graph){
        assert(s >= 0 && s < G.V());

        visited = new bool[G.V()];
        from = new int[G.V()];
        for(int i = 0; i < G.V(); i++){
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;

        // 初始化路径相关信息
        dfs(s);
    }

    ~Path(){
        delete[] visited;
        delete[] from;
    }

    bool hasPath(int w){
        assert(w >= 0 && w < G.V());
        return visited[w];  // 从w到起始点,如果有路径, 那么遍历时一定会访问到, visited就会为true
    }


    void path(int w, vector<int> &vec){     // 传递的是vector的饮用
        stack<int> s;
        int p = w;
        while(p != -1){     // 从w倒推到起始点的路径, 起始点的 from 为 -1
            s.push(p);
            p = from[p];
        }
        vec.clear();        // 以防万一, 先清空
        while (!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
    }

    void showPath(int w){
        vector<int> vec;
        path(w, vec);
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i];
            if(i == vec.size() -1)
                cout << endl;
            else
                cout << "->";
        }
    }

};


#endif //ALGORITHM_PATH_H
