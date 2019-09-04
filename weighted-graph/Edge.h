//
// Created by Daolin on 2019/8/21.
//

#ifndef ALGORITHM_EDGE_H
#define ALGORITHM_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Weight>
class Edge{
private:
    // 对于无向边a, b顺序不重要
    // 对于有向边, a指向b
    int a, b;
    Weight weight;

public:
    Edge(int a, int b, Weight weight){
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    Edge(){}

    ~Edge(){}

    int v(){ return a; }

    int w(){ return b; }

    Weight wt(){ return weight; }

    int other(int x){
        assert( x == a || x == b);
        return x == a ? b : a;
    }

    friend ostream& operator <<(ostream &os, const Edge &e){
        os << e.a << "-" << e.b << ": " << e.weight;
        return os;
    }

    bool operator < (Edge<Weight> &e){
        return weight < e.wt();
    }

    bool operator > (Edge<Weight> &e){
        return weight > e.wt();
    }

    bool operator == (Edge<Weight> &e){
        return weight == e.wt();
    }

    bool operator <= (Edge<Weight> &e){
        return weight <= e.wt();
    }

    bool operator >= (Edge<Weight> &e){
        return weight >= e.wt();
    }

};

#endif //ALGORITHM_EDGE_H
