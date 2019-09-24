//
// Created by Daolin on 2019/9/22.
//
#include <queue>
#include <stack>
#include "TreeNode.h"

/**
 * 非递归中序遍历, 可以提前终止
 */

struct Command{
    TreeNode* node;
    bool visited;
    Command(TreeNode* node, bool visited):node(node), visited(visited){}
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        stack<Command> stack;
        stack.push(Command(root, false));
        int count = 0;
        while(!stack.empty()){
            Command c = stack.top();
            stack.pop();
            if(!c.visited){
                if(c.node->right)
                    stack.push(Command(c.node->right,false));
                c.visited = true;
                stack.push(c);
                if(c.node->left)
                    stack.push(Command(c.node->left, false));
            }else{
                count ++;
                if(count == k)
                    return c.node->val;
            }
        }
        return -1;
    }
};
