//
// Created by Daolin on 2020/7/3.
//

#ifndef ALGORITHM_SOLUTION2_H
#define ALGORITHM_SOLUTION2_H
#include "../commonHeader.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){

            if(!isEqualNode(q1.front(), q2.front()))
                return false;
            if(q1.front() != nullptr){
                q1.push(q1.front()->left);
                q1.push(q1.front()->right);
                q2.push(q2.front()->left);
                q2.push(q2.front()->right);
            }
            q1.pop(); q2.pop();
        }
        return q1.size() == q2.size();
    }
    bool isEqualNode(TreeNode* n1, TreeNode* n2){
        if(n1 == nullptr && n2 == nullptr) return true;
        if(n1 == nullptr || n2 == nullptr) return false;
        return n1->val == n2->val;
    }
};

#endif //ALGORITHM_SOLUTION2_H
