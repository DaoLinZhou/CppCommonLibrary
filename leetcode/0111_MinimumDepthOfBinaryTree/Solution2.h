//
// Created by Daolin on 2019/9/18.
//
#include "TreeNode.h"

/**
 * 代码更简洁
 */
class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->right)
            return 1 + minDepth(root->left);
        if(!root->left)
            return 1 + minDepth(root->right);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
