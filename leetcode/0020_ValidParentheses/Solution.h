//
// Created by Daolin on 2019/9/12.
//
#include <string>
#include <stack>
using namespace std;

/**
 * 这道题是使用栈进行辅助操作的经典题目
 * 没什么难点, 只要注意处理输入都是右括号的情况, 以及全部匹配之后stack还有剩余的情况就可以
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack1;
        for(int i = 0; i < s.length(); i++){
            // 如果是左边括号则放入
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack1.push(s[i]);
            else{   // 反之则是右边括号或非法字符, 此时要与stack中的元素匹配
                if(stack1.empty())      // 如果stack中没有元素
                    return false;
                else if(s[i] == ')' && stack1.top() == '(')
                    stack1.pop();
                else if(s[i] == ']' && stack1.top() == '[')
                    stack1.pop();
                else if(s[i] == '}' && stack1.top() == '{')
                    stack1.pop();
                else    // 说明stack中的元素和新的元素不匹配
                    return false;
            }
        }
        // 如果留有元素则不匹配
        return stack1.empty();
    }
};
