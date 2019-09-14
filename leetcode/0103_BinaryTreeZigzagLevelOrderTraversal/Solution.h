//
// Created by Daolin on 2019/9/14.
//
#include <queue>
#include <vector>
#include "TreeNode.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> queue;

        if(root)
            queue.push(pair<TreeNode*, int>(root, 0));
        while(!queue.empty()){
            auto combo = queue.front();
            queue.pop();
            if(combo.second == ret.size())
                ret.push_back({});
            ret[combo.second].push_back(combo.first->val);
            if (combo.first->left)
                queue.push(pair<TreeNode *, int>(combo.first->left, combo.second + 1));
            if (combo.first->right)
                queue.push(pair<TreeNode *, int>(combo.first->right, combo.second + 1));
        }

        // 进行反转
        reverse(ret);

        return ret;
    }

private:
    void reverse(vector<vector<int>>& vec){
        for(int i = 0; i < vec.size(); i++)
            // 当层序为 1, 3, 5 ... 时反转
            if(i & 1) reverseIntVec(vec[i]);
    }

    void reverseIntVec(vector<int>& vec){
        for(int i = 0; i < vec.size()/2; i++)
            swap(vec[i], vec[vec.size()-1-i]);
    }

};
