//
// Created by Daolin on 2019/9/13.
//

#include <vector>
#include "TreeNode.h"

/**
 * 递归写法
 */
class Solution {
public:
    vector<int> ret;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            ret.push_back(root->val);
        }
        return ret;
    }
};

