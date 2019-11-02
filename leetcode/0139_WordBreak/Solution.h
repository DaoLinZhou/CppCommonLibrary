//
// Created by Daolin on 2019/10/29.
//
#include "../commonHeader.h"

bool startWith(const string& s, int index, const string& word){
    if(s.length() < index + word.length())
        return false;
    for(int i = 0; i < word.length(); i++)
        if(s[index+i] != word[i])
            return false;
    return true;
}

class Solution {
private:
    bool tryFetch(const string& s, int startIndex, vector<string>& wordDict, vector<int>& memo){
        if(memo[startIndex] != -1)
            return memo[startIndex];
        bool res = (startIndex == s.size());
        for(int i = 0; i < wordDict.size(); i++)
            if(startWith(s, startIndex, wordDict[i]))
                res = res || tryFetch(s, startIndex + wordDict[i].size(), wordDict, memo);
        return memo[startIndex] = res;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /// memo中保存三种状态 -1 代表未被访问过, 0 代表没有word 和当前index的startWith匹配, 反之为 1
        vector<int> memo(s.size()+1, -1);
        return tryFetch(s, 0, wordDict, memo);
    }
};
