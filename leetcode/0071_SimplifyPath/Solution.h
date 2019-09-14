//
// Created by Daolin on 2019/9/12.
//

#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathStack;
        vector<string> vec = split(path, '/');
        // 三种情况
        for(auto item : vec){
            if(item == ".")
                continue;
            else if(item == "..") {
                if(!pathStack.empty())  // 为空时pop会产生异常
                    pathStack.pop();
            }else
                pathStack.push(item);
        }

        // 拼接字符串
        string ret = "";
        while (!pathStack.empty()){
            ret = "/" + pathStack.top() + ret;
            pathStack.pop();
        }
        return ret == "" ? "/" : ret;
    }

private:
    std::vector<string> split(string s, char c){
        int first = 0;
        vector<string> ret;
        string item = "";
        for(int i = 0; i < s.length(); i ++){
            if(s[i] == c){
                while(first < i) item += s[first++];
                first ++;
                if(item != "") {
                    ret.push_back(item);
                    item = "";
                }
            }
        }
        while (first < s.length()) item += s[first++];
        if(item != "")
            ret.push_back(item);
        return ret;
    }

};
