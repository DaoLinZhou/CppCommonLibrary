//
// Created by Daolin on 2019/9/22.
//
#include <vector>
#include <queue>
#include <unordered_set>
#include "TreeNode.h"

/**
 * 解题思路:
 * 平衡BST的顶点一定是给定有序数组的最中间的元素
 */

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedSubArrayToBST(nums, 0, nums.size()-1);
    }

    // 范围[l...r]
    TreeNode* sortedSubArrayToBST(vector<int>& vec, int l, int r){
        if(l > r)
            return nullptr;
        int mid = l + (r-l)/2;
        TreeNode* node = new TreeNode(vec[mid]);
        node->left = sortedSubArrayToBST(vec, l, mid-1);
        node->right = sortedSubArrayToBST(vec, mid+1, r);
        return node;
    }
};
