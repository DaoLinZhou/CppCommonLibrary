//
// Created by Daolin on 2019/9/22.
//

#include "TreeNode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(!root) return root;
        if(root->val == p->val || root->val == q->val)
            return root;
        auto x = lowestCommonAncestor(root->left, p, q);
        auto y = lowestCommonAncestor(root->right, p, q);
        if(x && y)  // 如果在左右两边都找到了, 说明p,q分别在root两侧, root就是根节点
            return root;
        return x ? x : y;   // 如果在同一侧, 就返回不为空的那个
    }
};
