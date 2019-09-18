//
// Created by Daolin on 2019/9/18.
//
#include <queue>
#include "TreeNode.h"

/**
 * 循环解法
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root)
            return true;
        queue<TreeNode*> queue;
        queue.push(root->left);
        queue.push(root->right);

        while(!queue.empty()){
            TreeNode* left = queue.front();
            queue.pop();
            TreeNode* right = queue.front();
            queue.pop();

            if(!left && !right)
                continue;
            if(!left || !right)
                return false;
            if(left->val != right->val)
                return false;
            queue.push(left->left);
            queue.push(right->right);
            queue.push(left->right);
            queue.push(right->left);
        }
        return true;
    }


};
