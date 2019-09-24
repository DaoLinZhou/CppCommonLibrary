//
// Created by Daolin on 2019/9/23.
//
#include <vector>
#include <string>

using namespace std;

const string digitsToChar[] = {
    " ",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

/**
 * 解题思路:
 *
 *  树形问题, 可以使用递归
 *
 *
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        string chars = digitsToChar[digits[0] - '0']; // 当前字符可以代表的所有字母
        string str = digits.substr(1,digits.size()-1);  // 除去当前字符
        vector<string> subRes = letterCombinations(str);    // 递归求后面的所有可能组成的string

        vector<string> res;

        if(subRes.empty()){     // 如果后面为空, 以string形式返回自身代表的所有字母
            for(char c : chars)
                res.push_back(string(1, c));
        }else{                  // 不为空, 则把自身和后面的string进行拼接
            for(char c : chars)
                for(string s : subRes)
                    res.push_back(c + s);
        }

        return res;
    }
};
