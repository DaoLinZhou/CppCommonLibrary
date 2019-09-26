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

class Solution {
private:
    // s中保存了此时从digits[0...index-1]翻译得到的一个字母字符串
    // 寻找和digits[index]匹配的字母, 获得digits[0...index]翻译得到的解
    void findCombination(const string& digits, int index, const string& s){
        if(index == digits.size()){
            // 此时s是问题的一个解, 保存s
            res.push_back(s);
            return;
        }
        char c = digits[index];
        string letter = digitsToChar[c-'0'];
        for (char i : letter)
            findCombination(digits, index+1, s + i);
    }
    vector<string> res;

public:
    vector <string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        findCombination(digits, 0, "");
        return res;
    }
};
