//
// Created by Daolin on 2019/9/13.
//

#include <vector>
#include <stack>
#include <unordered_set>
#include "TreeNode.h"

/**
 * 后序遍历的循环实现比前序的难一些
 * 基本思想如下:
 *
 * 从查看stack上的元素, 如果没访问过, 则把它左右子节点放入(先右后左)stack中, 标记它为已访问
 * 如果这个节点被访问过, 说明它的左右子树已经遍历完成(因为是stack), 把它pop并放入vec中
 *
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;                 // 模仿递归的辅助数据结构
        unordered_set<TreeNode*> visited;   // 标记节点是否被访问过

        if(root) s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            if(visited.find(node) == visited.end()){  // 这个节点没被访问过, 说明左右子树都没进行遍历
                if(node->right) s.push(node->right);
                if(node->left) s.push(node->left);
                visited.insert(node);    // 标记为已访问
            } else{     // 这个节点被访问过, 说明它左右子树都遍历完成
                s.pop();
                ret.push_back(node->val);
            }
        }
        return ret;
    }
};
