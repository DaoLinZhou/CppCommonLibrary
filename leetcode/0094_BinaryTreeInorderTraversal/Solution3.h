//
// Created by Daolin on 2019/9/14.
//

#include <vector>
#include <stack>
#include <cassert>
#include "TreeNode.h"

/// 设计模式 -- 命令模式
/// 用于模拟计算机指令
struct Command{
    string s;           // 用于描述命令是什么, go(访问), print(输出)
    TreeNode* node;     // 指令作用在这个节点上
    Command(string s, TreeNode* node):s(s), node(node){}
};

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<Command> stack;
        stack.push(Command("go", root));

        while(!stack.empty()){
            Command command = stack.top();
            stack.pop();

            // 分析command
            if(command.s == "print"){
                res.push_back(command.node->val);
            }else{
                // 中序遍历, 先访问左子树, 再自身, 再右子树
                // 所以放入栈中时要反过来, 先右子树, 再自身, 最后左子树
                assert(command.s == "go");
                if(command.node->right)
                    stack.push(Command("go", command.node->right));

                stack.push(Command("print", command.node));

                if(command.node->left)
                    stack.push(Command("go", command.node->left));
            }
        }
        return res;
    }
};
