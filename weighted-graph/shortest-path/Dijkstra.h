//
// Created by Daolin on 2019/8/27.
//

#ifndef ALGORITHM_DIJKSTRA_H
#define ALGORITHM_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include "../Edge.h"
#include "../../heap/IndexMinHeap.h"

template <typename Graph, typename Weight>
class Dijkstra{

private:
    Graph &G;
    int s;      // 起始点

    /**
     *  记录起始点到每一个点的最短距离 */
    Weight* distTo;

    bool* marked;

    /** 记录这个点是从那一条边来的,
     * 可以用来判断是否有路径到达这一点
     * 还可以用来逆推到达某一个点的路径 */
    vector<Edge<Weight>*> from;


public:
    Dijkstra(Graph &graph, int s):G(graph){
        assert(s >= 0 && s < G.V());
        // 初始化
        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for(int i = 0; i < G.V(); i++){
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }
        // 存储起始点到每个节点的最小权值
        IndexMinHeap<Weight> ipq(G.V());

        // Dijkstra
        distTo[s] = Weight();   // 如果Weight是int或double会默认初始化成0
        from[s] = new Edge<Weight>(s, s, Weight());
        ipq.insert(s, distTo[s]);
        marked[s] = true;
        while(!ipq.isEmpty()){
            int v = ipq.extractMinIndex();

            // distTo[v] 就是s到v的最短距离
            marked[v] = true;

            /** Relaxation */
            // 遍历v点所有相邻边
            typename Graph::adjIterator adj(G, v);
            for(Edge<Weight>* e = adj.begin(); !adj.isEnd(); e = adj.next()){
                // 通过相邻边获取相邻节点
                int w = e->other(v);
                // 如果 w 没被访问过
                if(!marked[w]){
                    // 同时没有去往 w 的路径, 或新路径(通过 v 点走向 w 的路径)比旧路径短, 就可以进行松弛操作
                    if(from[w] == NULL || distTo[v] + e->wt() < distTo[w]){
                        // 更新最短路径的值
                        distTo[w] = distTo[v] + e->wt();
                        // 更新去往 w 的边
                        from[w] = e;
                        if(ipq.contain(w))  // 如果已有就更新
                            ipq.change(w, distTo[w]);
                        else    // 把 w 放入最小索引堆
                            ipq.insert(w, distTo[w]);
                    }
                }
            }
        }
    }

    ~Dijkstra(){
        delete[] distTo;
        delete[] marked;
        delete from[0];
    }

    Weight shortestPathTo(int w){
        assert(hasPathTo(w));
        return distTo[w];
    }

    bool hasPathTo(int w){
        assert(w >= 0 && w < G.V());
        return marked[w];
    }

    void shortestPath(int w, vector<Edge<Weight>> &vec){
        assert(hasPathTo(w));
        stack<Edge<Weight>*> s;
        Edge<Weight>* e = from[w];
        while(e->v() != this->s){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);
        while(!s.empty()){
            e = s.top();
            vec.push_back(*e);
            s.pop();
        }
    }

    void showPath(int w){
        assert(hasPathTo(w));
        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i].v() << "->";
            if(i == vec.size()-1)
                cout << vec[i].w() << endl;
        }
    }

};


#endif //ALGORITHM_DIJKSTRA_H
