//
// Created by Daolin on 2019/9/20.
//
#include <vector>
#include "TreeNode.h"

class Solution {
public:
    vector <vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> v;
        pathSum(root, sum, res, v);
        return res;
    }

private:
    void pathSum(TreeNode* node, int sum, vector<vector<int>>& res, vector<int>& v){
        if(!node)
            return;
        v.push_back(node->val);

        // 到达叶子节点且总值为sum, 只有在这时才添加
        if(node->val == sum && !node->left && !node->right)
            res.push_back(v);

        pathSum(node->left, sum-node->val, res, v);
        pathSum(node->right, sum-node->val, res, v);
        v.pop_back();   // 因为前面push了, 而在返回到上一层时要进行pop
    }
};
