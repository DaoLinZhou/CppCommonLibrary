//
// Created by Daolin on 2019/9/20.
//
#include <vector>
#include <algorithm>
#include "TreeNode.h"
/**
 * 解题思路:
 * 先获取所有路径, 在看每个路径是否符合要求
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        auto allPath = getAllPath(root);
        vector<vector<int>> ret;
        for(auto path : allPath){
            if(isSameSum(path, sum)){
                reverse(path.begin(), path.end());
                ret.push_back(path);
            }
        }
        return ret;
    }

private:
    vector<vector<int>> getAllPath(TreeNode* node){
        if(!node)
            return {};
        if(!node->left && !node->right)
            return {{node->val}};
        vector<vector<int>> ret;
        auto leftVec = getAllPath(node->left);
        auto rightVec = getAllPath(node->right);
        for(auto vec : leftVec){
            vec.push_back(node->val);
            ret.push_back(vec);
        }
        for(auto vec : rightVec) {
            vec.push_back(node->val);
            ret.push_back(vec);
        }
        return ret;
    }

    bool isSameSum(const vector<int>& vec, int sum){
        for(int i : vec)
            sum -= i;
        return sum == 0;
    }

};
