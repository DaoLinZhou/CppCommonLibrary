//
// Created by Daolin on 2019/8/28.
//

#ifndef ALGORITHM_BELLMANFORD_H
#define ALGORITHM_BELLMANFORD_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "../Edge.h"

using namespace std;

template <typename Graph, typename Weight>
class BellmanFord{
private:
    Graph& G;
    int s;
    Weight* distTo;
    vector<Edge<Weight>*> from;
    bool hasNegativeCycle;

    bool detectNegativeCycle(){
        // 如果还能进行松弛操作, 就说明有负权环
        for(int i = 0; i < G.V(); i++){
            typename Graph::adjIterator adj(G, i);
            for(Edge<Weight>* e = adj.begin(); !adj.isEnd(); e = adj.next())
                if(from[e->w()] == NULL || distTo[e->v()] + e->wt() < distTo[e->w()])
                    return true;
        }
        return false;
    }

public:
    BellmanFord(Graph& graph, int s):G(graph){
        assert(s >= 0 && s < G.V());
        this->s = s;
        distTo = new Weight[G.V()];
        for(int i = 0; i < G.V(); i++){
            from.push_back(NULL);
        }

        // BellmanFord
        distTo[s] = Weight();
        // 对所有节点进行v-1次松弛操作
        for(int pass = 1; pass < G.V(); pass++){

            // 对每个节点进行一次松弛
            for(int i = 0; i < G.V(); i++){
                typename Graph::adjIterator adj(G, i);
                for(Edge<Weight>* e = adj.begin(); !adj.isEnd(); e = adj.next()){
                    // Relaxation 如果没访问过e->w(),或通过e->v()的路径比原本的路径更小
                    if(from[e->w()] == NULL || distTo[e->v()] + e->wt() < distTo[e->w()]){
                        distTo[e->w()] = distTo[e->v()] + e->wt();
                        from[e->w()] = e;
                    }
                }
            }
        }
        // 如果还能继续松弛就说明有负权环
        hasNegativeCycle = detectNegativeCycle();
    }

    ~BellmanFord(){
        delete[] distTo;
    }

    bool negativeCycle(){
        return hasNegativeCycle;
    }

    Weight shortestPathTo(int w){
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
        return distTo[w];
    }

    bool hasPathTo(int w){
        assert(w >= 0 && w < G.V());
        return from[w] != NULL;
    }

    void shortestPath(int w, vector<Edge<Weight>> &vec){
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);

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
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i].v() << "->";
            if (i + 1 == vec.size())
                cout << vec[i].w() << endl;
        }
    }

};

#endif //ALGORITHM_BELLMANFORD_H
