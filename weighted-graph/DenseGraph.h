//
// Created by Daolin on 2019/8/16.
//

#ifndef ALGORITHM_WIGHTED_DENSEGRAPH_H
#define ALGORITHM_WIGHTED_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

// 稠密图 - 邻接矩阵 - 有权图
template <typename Weight>
class DenseGraph{
private:
    int n, m;   // n 为节点数, m为边数
    bool directed;
    vector<vector<Edge<Weight>*>> g;

public:
    DenseGraph(int n, bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for(int i = 0; i < n; i ++){
            g.push_back(vector<Edge<Weight>*>(n , NULL));
        }
    }

    ~DenseGraph() {
        for(int i=0; i<g.size(); i++)
            for (int j = 0; j < g[i].size(); ++j)
                if(g[i][j] != NULL)
                    delete g[i][j];
    }

    int V(){return n;}
    int E(){return m;}

    void addEdge(int v, int w, Weight weight){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        if(hasEdge(v, w)){
            delete g[v][w];
            if(!directed)
                delete g[w][v];
            m --;
        }

        g[v][w] = new Edge<Weight>(v, w, weight);
        if(!directed)
            g[w][v] = new Edge<Weight>(w, v, weight);
        m ++;
    }

    bool hasEdge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w] != NULL;
    }

    void show(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                if(g[i][j])
                    cout << g[i][j]->wt() << "\t";
                else
                    cout << "NULL\t";
            cout << endl;
        }
    }

    // 相邻边的迭代器
    class adjIterator{
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(DenseGraph &graph, int v):G(graph){
            this->v = v;
            this->index = -1;
        }

        Edge<Weight>* begin(){
            index = -1;
            return next();
        }

        Edge<Weight>* next(){
            for(index += 1; index < G.V(); index++)
                if(G.g[v][index])
                    return G.g[v][index];
            return NULL;
        }

        bool isEnd(){
            return index >= G.V();
        }
    };

};

#endif //ALGORITHM_DENSEGRAPH_H
