//
// Created by Daolin on 2019/9/18.
//
#include "TreeNode.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        // 此时pq不全为空, 如果有一个为空就一定不相等
        if(!p || !q || p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
