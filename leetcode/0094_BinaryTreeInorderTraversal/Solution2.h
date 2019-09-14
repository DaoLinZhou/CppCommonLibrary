//
// Created by Daolin on 2019/9/13.
//
#include <vector>
#include "TreeNode.h"


class Solution {
public:
    // 中序遍历是先访问左子树, 在访问自身, 再访问右子树
    vector<int> ret;
    vector<int> inorderTraversal(TreeNode *root) {
        if(root){
            inorderTraversal(root->left);
            ret.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ret;
    }
};