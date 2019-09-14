//
// Created by Daolin on 2019/9/14.
//
#include <queue>
#include <vector>
#include "TreeNode.h"

/**
 * root从0层开始, 可以当作ret的index
 * 当层数等于size说明到了新的一层, 在ret尾部追加 vec
 * 优点: 代码简洁, 且可以不用对最后一排进行特殊操作
 *
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> queue;

        if(root)
            queue.push(pair<TreeNode*, int>(root, 0));
        while(!queue.empty()){
            auto combo = queue.front();
            queue.pop();

            // 当走到了新的一层
            if(combo.second == ret.size())
                ret.push_back({});

            ret[combo.second].push_back(combo.first->val);
            if (combo.first->left)
                queue.push(pair<TreeNode *, int>(combo.first->left, combo.second + 1));
            if (combo.first->right)
                queue.push(pair<TreeNode *, int>(combo.first->right, combo.second + 1));
        }

        return ret;
    }
};
