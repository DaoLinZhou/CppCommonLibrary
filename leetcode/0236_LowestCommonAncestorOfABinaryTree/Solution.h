//
// Created by Daolin on 2019/9/22.
//
#include "TreeNode.h"

/**
 * 解题思路:
 * 缺点, 耗时长, 多次重复计算isSubNode
 *
 * 判断p, q是否分别在左右子树两侧, 如果是, 则返回自身
 * 如果不是, 递归向下找
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val)
            return root;

        bool pInLeft = isSubNode(root->left, p);
        bool qInRight = isSubNode(root->right, q);
        if(pInLeft == qInRight)
            return root;
        if(pInLeft)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }

private:
    bool isSubNode(TreeNode* node1, TreeNode* node2){
        if(!node1) return false;
        if(node1->val == node2->val)
            return true;
        return isSubNode(node1->left, node2) || isSubNode(node1->right, node2);
    }
};
