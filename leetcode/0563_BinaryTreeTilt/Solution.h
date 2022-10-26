//
// Created by jiatang on 2022/7/29.
//

#ifndef CPPCOMMONLIBRARY_SOLUTION_H
#define CPPCOMMONLIBRARY_SOLUTION_H

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "../commonHeader.h"

class Solution {
public:
    int findTilt(TreeNode* root) {
        return this->compute(root).second;
    }

//    first is the sum of the tree
//    second is the Tilt of the tree
    pair<int, int> compute(TreeNode* node){

        if(node == nullptr){
            return {0, 0};
        }

        pair<int, int> l = this->compute(node->left);
        pair<int, int> r = this->compute(node->right);

        return {l.first + r.first + node->val, l.second + r.second + abs(l.first - r.first)};

    }
};

#endif //CPPCOMMONLIBRARY_SOLUTION_H
