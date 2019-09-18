//
// Created by Daolin on 2019/9/18.
//
#include <queue>
#include <stdexcept>
#include "TreeNode.h"

/**
 * 非递归
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        vector<TreeNode*> queue;
        queue.push_back(root);
        int i = 0;
        while(!queue.empty()){
            TreeNode* node = queue[i++];
            if(!node->right)
                return node->left ? queue.size()+1 : queue.size();
            queue.push_back(node->left);
            queue.push_back(node->right);
        }
        throw invalid_argument("no solution");
    }
};
