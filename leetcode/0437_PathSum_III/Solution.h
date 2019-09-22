//
// Created by Daolin on 2019/9/21.
//
#include "TreeNode.h"
/**
 * 解题思路
 */
class Solution {
public:
    /// 语义: 从root向下寻找(不一定包含root)和为sum的所有path
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        int res = findPath(root, sum);      /// 寻找以root为根的path

        /// 寻找不以root为根的path
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);

        return res;
    }

private:
    /// 语义: 寻找以node为根, 和为num的path的个数
    int findPath(TreeNode* node, int num){
        if(!node)
            return 0;
        int res = 0;
        if(node->val == num)    // 如果当前节点符合条件
            res += 1;
        /// 由于后面可能有val为负的节点, 可能依旧有和为num的组合, 所以应该继续向下找
        /// 但如果可以确保没有负val的节点, 就可以停止搜索了, 具体情况可以询问面试官, 但这道题可能有负数val
        res += findPath(node->left, num - node->val);
        res += findPath(node->right, num - node->val);
        return res;
    }
};
