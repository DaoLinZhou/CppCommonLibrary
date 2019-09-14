//
// Created by Daolin on 2019/9/14.
//

#include <vector>
#include <stack>
#include <cassert>
#include "TreeNode.h"

/**
 * 使用命令模式可以更好的模仿计算机栈的运行
 * 只要稍稍修改代码就可以实现后序遍历和中序遍历,
 * 具体可以看145 的Solution3 和 94的Solution3
 */

/// 设计模式 -- 命令模式
/// 用于模拟计算机指令
struct Command{
    string s;           // 用于描述命令是什么, go(访问), print(输出)
    TreeNode* node;     // 指令作用在这个节点上
    Command(string s, TreeNode* node):s(s), node(node){}
};

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
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
                // 前序遍历, 先访问自己, 再访问左子树, 再访问右子树
                // 所以放入栈中时要反过来, 先右子树, 再左子树, 最后自身
                assert(command.s == "go");
                if(command.node->right)
                    stack.push(Command("go", command.node->right));
                if(command.node->left)
                    stack.push(Command("go", command.node->left));
                stack.push(Command("print", command.node));
            }
        }
        return res;
    }
};