//
// Created by Daolin on 2019/8/15.
//

#ifndef ALGORITHM_UNIONFIND4_H
#define ALGORITHM_UNIONFIND4_H

#include <cassert>

namespace UF4{
    //quickUnion版本优化, union时会把rank小的指向rank大的
    class UnionFind {
    private:
        int count;
        int* parent;
        int* rank;

    public:
        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for(int i=0;i < n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete [] parent;
            delete [] rank;
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
            if(rank[pRoot] < rank[qRoot]){
                parent[pRoot] = qRoot;
            }else if(rank[pRoot] > rank[qRoot]){
                parent[qRoot] = pRoot;
            } else {    // rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }
        }
    };
}

#endif //ALGORITHM_UNIONFIND4_H
