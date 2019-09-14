//
// Created by Daolin on 2019/9/14.
//
#include <queue>
#include <vector>
#include "TreeNode.h"

/**
 * 解题思路:
 * 层序遍历, 每当访问新的一层时, 把上一个节点的值(preVal)返回, 即上一层最后一个节点
 * 需要对最后一层进行特殊处理
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<pair<TreeNode*, int>> q;
        if(!root)
            return {};

        // 当我们遍历第一层时, preVal并没有被赋值过
        // 所以我们希望从第二层开始进行push_back操作
        // 判断新的一层的条件是 combo.second == ret.size()
        // 后者在遍历第一层时没有任何元素, 所以为0
        // 因此我们让前者为-1就可以避开第一个元素
        // 因此我们把root的层数设为-1
        q.push(pair(root, -1));
        int preVal; // 保存前一个遍历到的值
        while(!q.empty()){
            auto combo = q.front();
            q.pop();

            if(combo.second == ret.size())
                ret.push_back(preVal);  // 放入上一层最后一个值
            // 暂存当前的值
            preVal = combo.first->val;
            if(combo.first->left)
                q.push(pair(combo.first->left, combo.second + 1));
            if(combo.first->right)
                q.push(pair(combo.first->right, combo.second + 1));
        }
        // 放入最后一层最后一个值
        ret.push_back(preVal);

        return ret;
    }
};
