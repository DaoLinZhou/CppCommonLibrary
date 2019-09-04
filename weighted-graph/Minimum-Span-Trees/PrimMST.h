//
// Created by Daolin on 2019/8/25.
//

#ifndef ALGORITHM_PRIMMST_H
#define ALGORITHM_PRIMMST_H

#include <iostream>
#include <cassert>
#include <vector>
#include "../Edge.h"
#include "../../heap/IndexMinHeap.h"

using namespace std;

template <typename Graph, typename Weight>
class PrimMST{
private:
    Graph &G;
    IndexMinHeap<Weight> ipq;       // 只保存权值
    vector<Edge<Weight>*> edgeTo;   // 存储和每个节点相邻的最短的横切边
    bool* marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visit(int v){
        assert(!marked[v]);
        marked[v] = true;

        // 遍历点v的相邻边
        typename Graph::adjIterator adj(G, v);
        for(Edge<Weight>* e = adj.begin(); !adj.isEnd(); e = adj.next()){
            // 从相邻边中取出相邻节点
            int w = e->other(v);
            // 如果没访问过
            if( !marked[w] ){
                if( !edgeTo[w] ){   // 当没有边和w连接时
                    ipq.insert(w, e->wt());     // 插入这条边
                    edgeTo[w] = e;  // 连接w的边是e
                }else if( e->wt() < edgeTo[w]->wt() ){  // 当有边和w连接, 并且旧的边比这条边大时
                    edgeTo[w] = e;  // 连接w的边是e
                    // 更新index w在索引堆中的值
                    ipq.change(w, e->wt());
                }
                // 当有边和w连接, 并且旧的边比这条边小时, 什么都不做
            }
        }
    }

public:
    PrimMST(Graph &graph):G(graph), ipq(IndexMinHeap<double>(graph.V())){
        marked = new bool[G.V()];
        for(int i=0; i < G.V(); i++){
            marked[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();

        // Prim
        visit(0);
        while( !ipq.isEmpty() ){
            int v = ipq.extractMinIndex();  // 获取的是最小边的Index
            assert( edgeTo[v] );            // 确保有边连接v节点
            mst.push_back( *edgeTo[v] );    // 存入边
            visit(v);
        }

        // 计算mstWeight
        mstWeight = mst[0].wt();
        for(int i = 1; i < mst.size(); i++)
            mstWeight += mst[i].wt();
    }

    ~PrimMST(){
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    }

    Weight result(){
        return mstWeight;
    }

};

#endif //ALGORITHM_PRIMMST_H
