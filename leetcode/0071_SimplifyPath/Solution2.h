//
// Created by Daolin on 2019/9/12.
//
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/**
 * 思路和solution1一样, 不过使用vector, 并且使用内置getline函数
 *
 */

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> vec;
        stringstream ss(path);

        while(getline(ss, tmp, '/')){
            if(tmp == "" || tmp == ".") continue;
            if(tmp == ".." && !vec.empty()) vec.pop_back();
            else if (tmp != "..") vec.push_back(tmp);
        }

        for(auto path : vec) res = "/" + path + res;
        return res.empty() ? "/" : res;
    }
};
