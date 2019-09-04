//
// Created by Daolin on 2019/8/24.
//

#ifndef ALGORITHM_LAZYPRIMMST_H
#define ALGORITHM_LAZYPRIMMST_H

#include <iostream>
#include <vector>
#include "../Edge.h"
#include "../../heap/MinHeap.h"

template <typename Graph, typename Weight>
class LazyPrimMST{

private:
    Graph &G;
    MinHeap<Edge<Weight>> pq;   // 优先队列 Priority queue
    bool* marked;               // 记录每个节点是否被访问过
    vector<Edge<Weight>> mst;   // 存储最小生成树的所有边
    Weight mstWeight;           // 记录最小生成树的总权值

    void visit(int v){
        assert(!marked[v]);
        marked[v] = true;

        // 遍历相邻边
        typename Graph::adjIterator adj(G, v);
        for(Edge<Weight>* e = adj.begin(); !adj.isEnd(); e = adj.next()){
            /* 首先当前节点已经访问过了, 如果这个边的另一个节点也被访问过了,
             * 这就不是横切边, 只有当没被访问过时才把这条边加入优先队列   */
            if( !marked[e->other(v)] )
                pq.insert(*e);
        }
    }

public:
    LazyPrimMST(Graph &graph):G(graph), pq(MinHeap<Edge<Weight>>(graph.E())){
        // 初始化
        marked = new bool[G.V()];
        for(int i = 0; i < G.V(); i++)
            marked[i] = false;
        mst.clear();

        // Lazy Prim
        visit(0);
        while(!pq.isEmpty()){
            Edge<Weight> e = pq.extractMin();
            /* 当边加入时两边的节点是不同的, 但有可能通过其他边访问过另一个节点
             * 导致两边节点都被访问过了, 所以在取出时要检查一下 */
            if(marked[e.v()] == marked[e.w()])
                continue;
            // 通过检查就说明属于最小生成树, 保存进向量
            mst.push_back(e);
            /* 这条边的两头一边被访问过, 另一边没有,
             * 继续要访问没有被访问过的那个点*/
            if(!marked[e.v()])  // 如果v点没被访问, 就访问v
                visit(e.v());
            else                // 反之访问w, 因为必定有一点没被访问
                visit(e.w());
        }

        // 计算mstWeight
        mstWeight = mst[0].wt();
        for(int i=1; i<mst.size(); i++)
            mstWeight += mst[i].wt();
    }

    ~LazyPrimMST(){
        delete [] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    }

    Weight result(){
        return mstWeight;
    }

};

#endif //ALGORITHM_LAZYPRIMMST_H
