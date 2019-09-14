//
// Created by Daolin on 2019/9/14.
//
#include <queue>
#include <vector>
#include "TreeNode.h"

/**
 * 解题思路:
 * 层序遍历, 保存每层的所有节点
 * 遍历每层, 取出每层的最后一个元素组成vec返回
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> q;
        if(root)
            q.push(pair(root, 0));

        while(!q.empty()){
            auto combo = q.front();
            q.pop();

            if(combo.second == ret.size())
                ret.push_back({});

            ret[combo.second].push_back(combo.first->val);
            if(combo.first->left)
                q.push(pair(combo.first->left, combo.second + 1));
            if(combo.first->right)
                q.push(pair(combo.first->right, combo.second + 1));
        }

        vector<int> result;
        for(auto i : ret)
            result.push_back(i[i.size()-1]);
        return result;
    }
};
