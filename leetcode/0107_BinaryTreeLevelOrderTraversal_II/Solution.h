//
// Created by Daolin on 2019/9/14.
//
#include <vector>
#include <algorithm>
#include "queue"
#include "TreeNode.h"


/**
 * 解题思路:
 * 先进行深度遍历, 代码和 #102 一样, 再把结果反转返回
 */

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        return reverse(ret);
    }

private:
    vector<vector<int>>& reverse(vector<vector<int>>& vec){
        for(int i=0; i<vec.size()/2; i++)
            swap(vec[i], vec[vec.size()-i-1]);
        return vec;
    }
};
