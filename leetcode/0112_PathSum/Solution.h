//
// Created by Daolin on 2019/9/19.
//
#include "TreeNode.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   // 确保root不为空, 如果为空肯定没有任何值和sum匹配
            return false;
        if(!root->left && !root->right)     // 只有到叶子节点才对sum进行判断
            return root->val == sum;
        int next = sum - root->val;
        return hasPathSum(root->left, next) || hasPathSum(root->right, next);
    }
};
