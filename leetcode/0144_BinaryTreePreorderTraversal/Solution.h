//
// Created by Daolin on 2019/9/13.
//
#include <vector>
#include "TreeNode.h"

/**
 * 递归解法
 */
class Solution {
public:
    vector<int> ret;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
            ret.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ret;
    }
};
