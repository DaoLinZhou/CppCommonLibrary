//
// Created by Daolin on 2019/9/18.
//
#include "TreeNode.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};