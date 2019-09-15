//
// Created by Daolin on 2019/9/14.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;

/**
 * 解题思路:
 * 把所有char入栈, 当遇到')'就把当前栈中最后一个'('之上的char逆序放入stack中
 */

class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> stack;
        queue<char> q;
        for(char c : s){
            if(c == ')'){
                popAndPushinQueue(stack, q);
                dequeueToStack(stack, q);
            }else{  // 其余的直接放入
                stack.push_back(c);
            }
        }
        string ret = "";
        for(char c : stack)
            ret += c;
        return ret;
    }

private:
    // 把栈中直到 '(' 的元素放入queue
    void popAndPushinQueue(vector<char>& s, queue<char>& q){
        int index = s.size()-1;
        while(s[index] != '('){
            q.push(s[index--]);
            s.pop_back();
        }
        s.pop_back();
    }

    // 把queue中的元素放回栈
    void dequeueToStack(vector<char>& s, queue<char>& q){
        while(!q.empty()){
            s.push_back(q.front());
            q.pop();
        }
    }
};
