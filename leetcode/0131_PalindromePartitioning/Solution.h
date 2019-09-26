//
// Created by Daolin on 2019/9/25.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        partitionHelper(s, 0, vec);
        return res;
    }

private:
    vector<vector<string>> res;
    void partitionHelper(const string& s, int index, vector<string>& vec){
        if(index >= s.size()){
            res.push_back(vec);
            return;
        }
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                // 放入string并递归求解
                vec.push_back(s.substr(index, i - index + 1));
                partitionHelper(s, i + 1, vec);
                vec.pop_back();     // 把放入string的取出, 不然下一次循环时它还存在里面
            }
        }
    }

    // find s is palindrome from [l...r]
    bool isPalindrome(const string& s, int l, int r){
        while(l < r)
            if(s[l++] != s[r--])
                return false;
        return true;
    }
};
