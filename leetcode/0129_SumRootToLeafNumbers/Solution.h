//
// Created by Daolin on 2019/9/20.
//
#include <vector>
#include "TreeNode.h"

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        auto subNodes = allSubNodes(root);
        int sum = 0;
        for(auto vec : subNodes)
            sum += getSum(vec);
        return sum;
    }

private:
    vector<vector<int>> allSubNodes(TreeNode* node){
        if(!node)
            return {};
        if(!node->left && !node->right)
            return {{node->val}};
        vector<vector<int>> res;
        auto leftVec = allSubNodes(node->left);
        auto rightVec = allSubNodes(node->right);
        for(auto v : leftVec){
            v.push_back(node->val);
            res.push_back(v);
        }
        for(auto v : rightVec){
            v.push_back(node->val);
            res.push_back(v);
        }
        return res;
    }

    int getSum(vector<int> vec){
        int sum = 0;
        for(int i = vec.size()-1; i >= 0; i--)
            sum = sum*10 + vec[i];
        return sum;
    }
};
