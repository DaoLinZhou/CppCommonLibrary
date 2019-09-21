//
// Created by Daolin on 2019/9/20.
//
#include <vector>
#include <string>
#include "TreeNode.h"

/**
 * 解题思路:
 * 一定要注意递归调用的语义
 * 都写在下面了, 注意, 递归终止条件有两个, 一个是当前节点为空, 一个是递归到叶子节点
 */

class Solution {
public:
    // 获取从这个点到叶子节点的路径
    vector<string> binaryTreePaths(TreeNode* root) {
        // 如果当前节点为空, 直接返回空
        if(!root)
            return {};

        // 如果当前节点为叶子节点, 返回自身的to_string值
        string str_val = to_string(root->val);
        if(!root->left && !root->right)
            return {str_val};

        // 用于记录要返回的值
        vector<string> ret;

        // 如果左子树有路径则把每个路径前面都加上自身的to_string
        vector<string> leftRes = binaryTreePaths(root->left);
        for ( string s : leftRes )
            ret.push_back(str_val + "->" + s);

        // 右子树同理
        vector<string> rightRes = binaryTreePaths(root->right);
        for ( string s : rightRes )
            ret.push_back(str_val + "->" + s);
        return ret;
    }
};
