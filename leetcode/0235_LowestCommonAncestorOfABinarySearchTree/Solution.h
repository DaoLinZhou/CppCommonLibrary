//
// Created by Daolin on 2019/9/21.
//
#include <cassert>
#include "TreeNode.h"

/**
 * 解题思路:
 *
 * 递归解法
 *
 * 一共有四种情况,
 *      1. 当p, q分别在root两侧时, root就是他们的公共父节点
 *      2. 当p, q都在root的右侧时, 递归从右子树寻找
 *      3. 同理, 都在左侧时, 递归从左子树寻找
 *      4. 当p, q中, 其中一个是另一个的父节点时, 这个节点就是公共父节点
 *
 *      1, 4 可以合并, 如果root不满足2, 3, 则一定满足1, 4, 而此时的root就是我们要返回的节点
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        assert(root && p && q);

        /// 当p,q 都在root的左子树时
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        /// 当p,q 都在root的右子树时
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        /// 如果, p,q分别在root的左右两侧, 说明root就是最近的父节点
        /// 还有可能, root->val 和p, q 的一个的val相等, 此时root也是我们要找的节点
        return root;
    }
};
