//
// Created by Daolin on 2019/10/10.
//
#include "../TreeNode.h"
#include "../commonHeader.h"

/**
 * 解题思路:
 *
 *  对于每个节点都有两种情况:
 *  1. 选取它, 同时选取它子节点的子节点们的最优解
 *  2. 不选它, 选它子节点的最优解
 *  除此之外再判空一下就好了
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
        if(node->left == NULL && node->right == NULL)
            return node->val;

        if(map.count(node))
            return map[node];

        int res;

        if(node->left == NULL)
            res = max(tryRob(node->right), node->val + tryRob(node->right->right) + tryRob(node->right->left));
        else if(node->right == NULL)
            res = max(tryRob(node->left), node->val + tryRob(node->left->left) + tryRob(node->left->right));
        else{
            res = max( tryRob(node->left) + tryRob(node->right), node->val
                    + tryRob(node->right->right)
                    + tryRob(node->right->left)
                    + tryRob(node->left->right)
                    + tryRob(node->left->left));
        }

        map[node] = res;
        return res;
    }

public:
    int rob(TreeNode* root) {
        return tryRob(root);
    }
};
