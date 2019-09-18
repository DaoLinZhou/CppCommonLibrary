//
// Created by Daolin on 2019/9/18.
//
#include "TreeNode.h"

/**
 * 解题思路:
 * 确保当前左右子树高度差小于等于1
 * 在检查左右子树是否为平衡二叉树
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if(abs(l-r) > 1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getHeight(TreeNode* node){
        if(!node)
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};
