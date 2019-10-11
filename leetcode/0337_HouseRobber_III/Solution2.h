//
// Created by Daolin on 2019/10/10.
//
#include "../commonHeader.h"
#include "../TreeNode.h"

/**
 * Solution1 的简化版本
 */

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
private:
    unordered_map<TreeNode*, int> map;

    int tryRob(TreeNode* node){
        if(node == NULL)
            return 0;
        /// 如果存储了值, 直接返回
        if(map.count(node))
            return map[node];

        int res = node->val;
        if(node->left)
            res += tryRob(node->left->left) + tryRob(node->left->right);
        if(node->right)
            res += tryRob(node->right->right) + tryRob(node->right->left);

        res = max(res, tryRob(node->left) + tryRob(node->right));
        map[node] = res;
        return res;
    }

public:
    int rob(TreeNode* root) {
        return tryRob(root);
    }
};
