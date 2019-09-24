//
// Created by Daolin on 2019/9/22.
//
#include "TreeNode.h"

/**
 * 解题思路:
 * 找到当前节点的左子树包含元素个数
 *      如果个数 + 1 == k, 说明当前节点就是我们要找到元素
 *      如果个数小于k说明我们要找到再右子树, 于是寻找右子树第 k - leftNum - 1 个最小的元素, 因为比他小的有 leftNum+1个
 *      如果leftNum > k 继续再左子树寻找第k小的元素
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int leftNum = countNode(root->left);
        if(leftNum + 1 == k)
            return root->val;
        else if(leftNum < k)
            return kthSmallest(root->right, k - leftNum - 1);
        else
            return kthSmallest(root->left, k);
    }

private:
    int countNode(TreeNode* node){
        if(!node)
            return 0;
        return 1 + countNode(node->left) + countNode(node->right);
    }
};
