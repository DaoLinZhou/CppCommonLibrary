//
// Created by Daolin on 2019/8/15.
//

#ifndef ALGORITHM_UNIONFIND5_H
#define ALGORITHM_UNIONFIND5_H

#include <cassert>

namespace UF5{

    // 路径压缩
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
            count = n;
        }

        ~UnionFind() {
            delete [] parent;
            delete [] rank;
        }

        int find(int p){
            assert(p >= 0 && p < count);
//            while (p != parent[p]) {
//                // 压缩方案1
//                // parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//            return p;
            if(p != parent[p])
                parent[p] = find(parent[p]);
            return parent[p];
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


#endif //ALGORITHM_UNIONFIND5_H
