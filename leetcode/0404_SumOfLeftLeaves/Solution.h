//
// Created by Daolin on 2019/9/19.
//
#include "TreeNode.h"

/**
 * 解题思路:
 * 判断作子节点是否为叶子节点, 如果是, 返回它的值和右子树的sumOfLeftLeaves的结果
 * 不然继续递归
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left && isLeaf(root->left))    // 如果左子节点是叶子节点
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }

private:
    inline bool isLeaf(TreeNode* node){
        return !node->left && !node->right;
    }
};
