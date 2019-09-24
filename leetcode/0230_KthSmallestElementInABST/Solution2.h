//
// Created by Daolin on 2019/9/22.
//
#include <vector>
#include "TreeNode.h"

/**
 * 解题思路:
 * 递归中序遍历
 * 中序遍历就是从小到大遍历
 * 遍历完成后取出数组中第k-1位的元素
 *
 */

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        vector<int> vec;
        inOrder(root, vec);
        return vec[k-1];
    }

private:
    void inOrder(TreeNode* node, vector<int>& vec){
        if(node){
            inOrder(node->left, vec);
            vec.push_back(node->val);
            inOrder(node->right, vec);
        }
    }
};
