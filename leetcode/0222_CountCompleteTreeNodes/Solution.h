//
// Created by Daolin on 2019/9/18.
//

#include "TreeNode.h"

/**
 * 通用解法, 对于所有二叉树都适用,
 * 但没有用到完全二叉树的特性
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int l = countNodes(root->left);
        int r = countNodes(root->right);
        return l+r+1;
    }
};