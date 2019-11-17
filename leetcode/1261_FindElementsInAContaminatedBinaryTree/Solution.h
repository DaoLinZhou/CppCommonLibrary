//
// Created by Daolin on 2019/11/17.
//
#include "../commonHeader.h"

class FindElements {
public:
    TreeNode* rnode;
    unordered_set<int> set;

    FindElements(TreeNode* root) {
        root->val = 0;
        rnode = root;
        init(root->left, 0, true);
        init(root->right, 0, false);
    }

    void init(TreeNode* node, int parent, bool left){
        if(node == nullptr)
            return;
        if(left)
            node->val = parent*2+1;
        else
            node->val = parent*2+2;
        set.insert(node->val);
        init(node->left, node->val, true);
        init(node->right, node->val, false);
    }

    bool find(int target) {
        return set.count(target);
        // return findFrom(rnode, target);
    }

    // bool findFrom(TreeNode* node, int target){
    //     if(node == nullptr)
    //         return false;
    //     if(node->val == target)
    //         return true;
    //     if(node->val > target)
    //         return false;
    //     return findFrom(node->left, target) || findFrom(node->right, target);
    // }

};
