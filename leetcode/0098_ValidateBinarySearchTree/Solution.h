//
// Created by Daolin on 2019/9/21.
//
#include <vector>
#include "TreeNode.h"

/**
 * 解题思路:
 * 利用中序遍历二分搜索树的特点进行判断
 *
 * 中序遍历一个二分搜索树是由小到大进行对所有元素进行遍历,
 * 若以当遍历完成后, 对遍历结果进行判断它是否为顺序
 */

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);

        for(int i = 1; i < vec.size(); i++)
            // 根据题意, 必须是后一个元素大于前一个元素, 等于也不行
            if(vec[i-1] >= vec[i])
                return false;
        return true;
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
