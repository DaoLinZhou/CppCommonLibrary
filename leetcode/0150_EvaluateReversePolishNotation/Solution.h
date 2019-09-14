//
// Created by Daolin on 2019/9/12.
//
#include <stack>
#include <string>
#include <vector>
using namespace std;

/**
 * 解题思路:
 * 使用stack, 如果匹配到一个运算符就pop两个数进行运算, 把结果再push进stack
 * 这里我们假设tokens是合法的
 * 注意, 运算时是后pop的元素对先pop的元素进行运算
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);    // 加法顺序无所谓
            }else if(tokens[i] == "-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);  // 后pop的元素对先pop的元素进行运算
            }else if(tokens[i] == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b * a);
            }else if(tokens[i] == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);
            }else{  // 说明是数字
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
