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

    vector<int> postorderTraversal(TreeNode* root) {
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
                // 后序遍历, 先访问左子树, 再访问右子树, 最后访问自身
                // 所以放入栈中时要反过来, 先自身, 再右子树, 再左子树
                assert(command.s == "go");
                stack.push(Command("print", command.node));
                if(command.node->right)
                    stack.push(Command("go", command.node->right));
                if(command.node->left)
                    stack.push(Command("go", command.node->left));
            }
        }
        return res;
    }
};
