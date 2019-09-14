//
// Created by Daolin on 2019/9/13.
//

#include <vector>
#include <stack>
#include "TreeNode.h"

/**
 * 递归和栈有密切的关系, 因为系统就是通过栈来实现递归
 * 所以当问题需要我们使用循环是, 我们可以自己实现栈来模仿递归
 */
class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> nodeStack;
        if(!root) return {};

        nodeStack.push(root);
        while(!nodeStack.empty()){
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            ret.push_back(node->val);
            if(node->right) nodeStack.push(node->right);
            if(node->left) nodeStack.push(node->left);
        }
        return ret;
    }
};
