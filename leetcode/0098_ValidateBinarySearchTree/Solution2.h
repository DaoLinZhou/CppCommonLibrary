//
// Created by Daolin on 2019/9/21.
//
#include "TreeNode.h"

/**
 * Solution1 的优化, 提前终止
 */

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        bool res = true;
        inOrder(root, res);
        return res;
    }

private:
    // pre 代表中序遍历形成数组(并不真实存在)时, 当前node前一个节点的值
    int* pre = NULL;
    void inOrder(TreeNode* node, bool& res){
        if(node){
            // 先递归左子树, 递归完成后 pre会指向左子树的最大值(如果是BST)
            // (如果不是BST, 会直接终止返回并把res设置为false, 而inOrder遍历时,
            // 没有赋值res为true的语句, 所以一但有一次赋值为false, 总体结果就是false)
            inOrder(node->left, res);

//            if(!res) return;  所以如果res在inOrder过程中变为false可以直接终止所有遍历, 但实际上这个步骤反而会降低速度

            // 判断左子树的最大值是否大于等于当前节点
            if(pre != NULL && *pre >= node->val){
                res = false;
                return;
            }
            // 在遍历右子树前, 要把最大值设为当前节点
            pre = &node->val;
            // 递归遍历右子树, pre会在返回上一层之前指向最大值
            inOrder(node->right, res);

//            if(!res) return;
        }
    }
};
