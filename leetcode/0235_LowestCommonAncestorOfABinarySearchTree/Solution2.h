//
// Created by Daolin on 2019/9/21.
//
#include "TreeNode.h"

/**
 * 解题思路:
 * 和 Solution1 一样,
 * 但是循环解法
 */

// 提速
static int fast_io = []() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        while(root){
            if(root->val > p->val && root->val > q->val)
                root = root->left;
            else if(root->val < p->val && root->val < q->val)
                root = root->right;
            else
                return root;
        }
        return nullptr;
    }
};
