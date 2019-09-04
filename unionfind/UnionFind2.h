//
// Created by Daolin on 2019/8/14.
//

#ifndef ALGORITHM_UNIONFIND2_H
#define ALGORITHM_UNIONFIND2_H

#include <cassert>

namespace UF2 {
    //QuickUnion版本
    class UnionFind {
    private:
        int count;
        int* parent;

    public:
        UnionFind(int n) {
            parent = new int[n];
            for(int i=0;i < n; i++)
                parent[i] = i;
        }

        ~UnionFind() {
            delete [] parent;
        }

        int find(int p){
            assert(p >= 0 && p < count);
            while (p != parent[p])
                p = parent[p];
            return p;
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if(pRoot == qRoot)
                return;
            parent[pRoot] = qRoot;
        }

    };
}


#endif //ALGORITHM_UNIONFIND2_H
