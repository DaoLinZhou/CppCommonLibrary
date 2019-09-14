//
// Created by Daolin on 2019/9/14.
//

#include <vector>
#include <queue>
#include "TreeNode.h"

/**
 * 解题思路:
 * 广度优先遍历, 记录顺便记录层数,
 * 每到新的一层就把旧的一层的vec放入结果中
 * 最后特殊处理最后一层的vec
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> item;
        queue<pair<TreeNode*, int>> queue;

        if(root)
            queue.push(pair<TreeNode*, int>(root, 1));
        int level = 1;
        while(!queue.empty()){
            auto combo = queue.front();
            queue.pop();
            // 第一次遍历到下一层的节点
            if(combo.second != level){
                level++;
                ret.push_back(item);   // 把上一层的放入
                item.clear();          // 清空, 为这一次元素做准备
            }
            item.push_back(combo.first->val);
            if(combo.first->left)
                queue.push(pair<TreeNode*, int>(combo.first->left, combo.second+1));
            if(combo.first->right)
                queue.push(pair<TreeNode*, int>(combo.first->right, combo.second+1));
        }
        // 因为是走到下一层第一个节点才把上一次的vec push进ret, 所以最后一层要单独进行push
        if(!item.empty()) ret.push_back(item);
        return ret;
    }
};

