//
// Created by Daolin on 2019/9/21.
//
#include "TreeNode.h"

/**
 * 解题思路:
 * 当我们找到要删除的那个节点时, 有三种可能
 *      1. 没有左子树, 那么直接返回这个节点的右子树, 返回到递归的上一层挂载
 *      2. 没有右子树, 同理返回左子树
 *      3. 当同时有左右子树时, 寻找前驱(大于它的最小节点)或后继(小于它的最大节点)
 *          之后把前驱或后继的左右子树赋值为要删除节点的左右子树(删除前驱或后继后的)
 */

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr;
        }else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }else if(key < root->val){
            root->left =  deleteNode(root->left, key);
        }else{  // 当前node就是我们要delete的node
            /// 当左右两个子树有一个为空时
            if(!root->left){
                auto tmp = root->right;
                delete root;
                return tmp;
            }
            if(!root->right) {
                auto tmp = root->left;
                delete root;
                return tmp;
            }
            /// 都不为空时, 找到前驱
            TreeNode* sucNode = new TreeNode(predecessor(root->right)->val);
            sucNode->left = root->left;
            sucNode->right = removeMin(root->right);    // 删除前驱那个节点
            delete root;
            return sucNode;
        }
        return root;
    }

private:
    // node不为空, 以node为根的最小node
    TreeNode* predecessor(TreeNode* node){
        while(node->left)
            node = node->left;
        return node;
    }

    // 删除以node为根的最小节点(最左叶子节点)
    TreeNode* removeMin(TreeNode* node){
        if(!node->left) {
            auto rightNode = node->right;
            delete node;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }
};
