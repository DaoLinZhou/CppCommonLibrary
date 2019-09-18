//
// Created by Daolin on 2019/9/18.
//
#include "TreeNode.h"

/**
 * 递归解法
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetric(root->left, root->right);
    }

private:
    // 判断两个Tree是否对称
    bool isSymmetric(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;
        // 此时node1和node2必定有值
        if(node1->val != node2->val) return false;
        return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
    }
};