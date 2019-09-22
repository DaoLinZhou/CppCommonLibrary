//
// Created by Daolin on 2019/8/15.
//

#ifndef ALGORITHM_UNIONFIND3_H
#define ALGORITHM_UNIONFIND3_H

#include <cassert>

namespace UF3{
    //quickUnion版本优化, union时会把个数少的的指向个数多的
    class UnionFind {
    private:
        int count;
        int* parent;
        int* sz;

    public:
        UnionFind(int n) {
            parent = new int[n];
            sz = new int[n];
            for(int i=0;i < n; i++) {
                parent[i] = i;
                sz[i] = 1;
            }
            count = n;
        }

        ~UnionFind() {
            delete [] parent;
            delete [] sz;
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
            if(sz[pRoot] < sz[qRoot]){
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }else{
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }
    };
}

#endif //ALGORITHM_UNIONFIND3_H
