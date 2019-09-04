//
// Created by Daolin on 2019/8/18.
//

#ifndef ALGORITHM_SHORTESTPATH_H
#define ALGORITHM_SHORTESTPATH_H

#include <iostream>
#include <cassert>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

template <typename Graph>
class ShortestPath{
private:
    Graph &G;
    bool* visited;
    int* from;
    int s;  // 起始点
    int* ord;

public:
    ShortestPath(Graph &graph, int s):G(graph){

        assert(s >= 0 && s < graph.V());

        this->s = s;
        visited = new bool[graph.V()];
        from = new int[graph.V()];
        ord = new int[graph.V()];
        for(int i=0; i < graph.V(); i++){
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }


        queue<int> q;
        q.push(s);
        visited[s] = true;
        ord[s] = 0;

        int count = 1;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            typename Graph::adjIterator adj(G, p);

            for(int i=adj.begin(); !adj.isEnd(); i = adj.next()){
                if(!visited[i]){
                    visited[i] = true;
                    from[i] = p;
                    ord[i] = count;
                    q.push(i);
                }
            }
            count ++;
        }
    }

    ~ShortestPath() {
        delete[] visited;
        delete[] from;
    }

    bool hasPath(int w){
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec){
        stack<int> s;
        int p = w;
        while(p != -1){
            s.push(p);
            p = from[p];
        }
        vec.clear();
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

    int length(int w){
        assert(w >= 0 && w < G.V());
        return ord[w];
    }

};




#endif //ALGORITHM_SHORTESTPATH_H
