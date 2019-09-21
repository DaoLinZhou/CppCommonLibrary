//
// Created by Daolin on 2019/9/20.
//
#include "TreeNode.h"
/**
 * 解题思路:
 * 通过递归不断向下一层寻找, 同时记录经过的值的和,
 * 当递归到底, 即到达叶子节点, 在总和中加上记录的值
 */

class Solution {
private:
    int ans = 0;

    // 假设node不能为空, now代表上一次的值
    void recursion(TreeNode* node, int now){
        now = now * 10 + node->val;
        // 如果是叶子节点, 说明当前递归完成, 在总和中加入now的值
        if(!node->left && !node->right)
            ans += now;
        // 继续递归
        if(node->left) recursion(node->left, now);
        if(node->right) recursion(node->right, now);
    }

public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        recursion(root, 0);
        return ans;
    }
};
