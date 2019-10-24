//
// Created by Daolin on 2019/10/11.
//
#include "../commonHeader.h"
#include "../TreeNode.h"

// 参考: https://www.cnblogs.com/grandyang/articles/5275096.html
class Solution {
public:
    // 加速
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int rob(TreeNode *root) {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }

    pair<int, int> dfs(TreeNode* node){
        if(!node) return {0, 0};
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);

        /// res.first 是不包含当前节点值的最大值
        /// res.second 是包含当前节点值的最大值
        pair<int, int> res;
        /// 所以first就是左子节点两种情况的较大值加上右子节点两种情况的较大值
        res.first = max(left.first, left.second) + max(right.first, right.second);
        /// 就是不包含左子节点值的最大值加上不包含右子节点值的最大值，和当前节点值之和
        res.second = left.first + right.first + node->val;
        return res;
    };

};
