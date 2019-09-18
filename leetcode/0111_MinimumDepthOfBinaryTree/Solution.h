//
// Created by Daolin on 2019/9/18.
//

#include "TreeNode.h"

/**
 * 效率更高
 *
 * 此题有陷阱, 当左右树中有一个为空时, 应该返回不为空的那个树的长度+1, 而不是0+1
 * 和就最大高度不一样
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        else if(!root->left && !root->right)
            return 1;
        else if(root->right && root->left)
            return 1 + min(minDepth(root->left), minDepth(root->right));
        else if(root->left)
            return minDepth(root->left) + 1;
        else
            return minDepth(root->right) + 1;
    }
};

