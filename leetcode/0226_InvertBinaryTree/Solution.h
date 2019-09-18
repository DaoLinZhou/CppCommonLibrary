//
// Created by Daolin on 2019/9/18.
//
#include "TreeNode.h"

/**
 * 这题太简单的, 搞不明白为什么Max Howell 为什么做不出来
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        invertTree(root->left); // 把左子树反转
        invertTree(root->right);    // 把右子树反转
        swap(root->left, root->right);  //反转当前左右子节点
        return root;
    }
};
