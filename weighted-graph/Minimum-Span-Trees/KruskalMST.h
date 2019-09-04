//
// Created by Daolin on 2019/8/25.
//

#ifndef ALGORITHM_KRUSKALMST_H
#define ALGORITHM_KRUSKALMST_H

#include <iostream>
#include <vector>
#include "../../heap/MinHeap.h"
#include "../../unionfind/UnionFind5.h"
#include "../Edge.h"

using namespace std;

template <typename Graph, typename Weight>
class KruskalMST{

private:
    // 因为不需要辅助函数, 所以也不需要存一份graph的引用
    vector<Edge<Weight>> mst;
    Weight mstWeight;

public:
    KruskalMST(Graph &graph){
        MinHeap<Edge<Weight>> pq( graph.E() );
        // 遍历所有节点
        for(int i = 0; i < graph.V(); i++){
            // 把所有节点的相邻边都添加到优先队列中
            typename Graph::adjIterator adj(graph, i);
            for(Edge<Weight>* e = adj.begin(); !adj.isEnd(); e = adj.next()){
                /* 由于图是无向的, 所以要防止边的重复添加
                 * 例如 1<->2 这条边, 只添加1->2, 不添加2->1 */
                if( e->v() < e->w() )
                    pq.insert(*e);
            }
        }
        // 自己实现的并查集
        UF5::UnionFind uf(graph.V());
        while( !pq.isEmpty() && mst.size() < graph.V() - 1 ){
            Edge<Weight> e = pq.extractMin();
            // 如果两点已经连接, 再连接就会成为环
            if(uf.isConnected(e.v(), e.w()))
                continue;
            mst.push_back(e);
            uf.unionElements(e.v(), e.w());
        }

        mstWeight = mst[0].wt();
        for(int i = 1; i < mst.size(); i++)
            mstWeight += mst[i].wt();
    }

    ~KruskalMST(){}

    vector<Edge<Weight>> mstEdges(){
        return mst;
    }

    Weight result(){
        return mstWeight;
    }

};

#endif //ALGORITHM_KRUSKALMST_H
