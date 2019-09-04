//
// Created by Daolin on 2019/8/27.
//

#ifndef ALGORITHM_DIJKSTRA_DAOLIN_H
#define ALGORITHM_DIJKSTRA_DAOLIN_H

#include <iostream>
#include <vector>
#include <stack>
#include "../Edge.h"
#include "../../heap/IndexMinHeap.h"

template <typename Graph, typename Weight>
class Dijkstra{
private:
    Graph &G;
    int s;

    Weight* distTo;
    bool* marked;
    vector<Edge<Weight>*> from;

public:
    Dijkstra(Graph& graph, int s):G(graph){
        assert( s >= 0 && s < G.V() );
        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for(int i = 0; i < G.V(); i++){
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }
        IndexMinHeap<Weight> ipq(G.V());

        distTo[s] = Weight();
        marked[s] = true;
        from[s] = new Edge<Weight>(s, s, Weight());

        ipq.insert(s, distTo[s]);
        while ( !ipq.isEmpty() ){
            int v = ipq.extractMinIndex();

            marked[v] = true;

            typename Graph::adjIterator adj(G, v);
            for(Edge<Weight>* e = adj.begin(); !adj.isEnd(); e = adj.next()){
                int w = e->other(v);
                if(!marked[w]){
                    if(from[w] == NULL || e->wt() + distTo[v] < distTo[w]){
                        distTo[w] = e->wt() + distTo[v];
                        from[w] = e;
                        if(ipq.contain(w))
                            ipq.change(w, distTo[w]);
                        else
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

    bool hasPathTo(int w){
        assert( w >= 0 && w < G.V());
        return marked[w];
    }

    Weight shortestPathTo(int w){
        assert(hasPathTo(w));
        return distTo[w];
    }

    void shortestPath(int w, vector<Edge<Weight>>& v){
        assert(hasPathTo(w));
        stack<Edge<Weight>*> s;
        Edge<Weight>* e = from[w];
        while (e->v() != this->s){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);
        while(!s.empty()){
            e = s.top();
            v.push_back(*e);
            s.pop();
        }
    }

    void showPath(int w){
        assert(hasPathTo(w));
        vector<Edge<Weight>> v;
        shortestPath(w, v);

        for(int i = 0; i < v.size(); i++){
            cout << v[i].v() << "->";
            if(i + 1 == v.size())
                cout << v[i].w() << endl;
        }
    }



};

#endif //ALGORITHM_DIJKSTRA_DAOLIN_H
