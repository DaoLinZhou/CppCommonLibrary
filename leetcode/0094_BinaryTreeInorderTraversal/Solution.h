//
// Created by Daolin on 2019/9/13.
//
#include <vector>
#include <stack>
#include <unordered_set>
#include "TreeNode.h"
/**
 * 做这种题, 首先要明白中序遍历是个什么样的过程
 *          其次要多在纸上画画
 *
 * 还有一种思路是每当访问一个节点, 把它的左右子节点还有自身放入stack中,
 * 之后把它的左右子节点设为空, 但我不想改变树的结构.
 */
class Solution {
public:
    // 中序遍历是先访问左子树, 在访问自身, 再访问右子树
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        unordered_set<TreeNode*> visited;

        if(root) s.push(root);

        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();

            // 有左子树, 同时自身没被访问过
            if(node->left && visited.find(node) == visited.end()){
                if(node->right) s.push(node->right);    // 先右子树
                s.push(node);                           // 再自身
                s.push(node->left);                     // 再左子树
                visited.insert(node);                   // 标记为已访问
            }else{  // 没有左子树 或者自身已被访问过
                // 访问自身
                ret.push_back(node->val);
                // 注意, 有可能这里我们访问过了node, 不应该再次将它的子树放入
                if(visited.find(node) == visited.end() && node->right) s.push(node->right);
            }
        }
        return ret;
    }
};
