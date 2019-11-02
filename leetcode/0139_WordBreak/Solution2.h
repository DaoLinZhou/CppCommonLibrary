//
// Created by Daolin on 2019/10/29.
//

#include "../commonHeader.h"

bool endWith(const string& s, int index, const string& word){
    if(index+1 < word.size())
        return false;
    for(int i = word.size()-1; i >= 0; i--, index--)
        if(s[index] != word[i])
            return false;
    return true;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /// 记录当前位置是否可以由word进行拼接组成(从前向后拼接)
        vector<bool> memo(s.size(), false);
        for(int i = 0; i < s.size(); i++)
            for(string& word : wordDict)
                if(endWith(s, i, word)) {
                    if (i + 1 == word.size())
                        /// 如果是在开头出现, 直接赋值为true
                        memo[i] = true;
                    else
                        /// 写法 1
                        /// 不然则判断连接这个word之前的那个位置是否可以由word拼接组成
                        /// 这里不应该直接赋值, 因为如果前一个word判断为true, 而下一个word判断为false, false会覆盖true
                        /// memo[i] = memo[i] || memo[i - word.size()];
                        memo[i] = memo[i - word.size()];
                    /// 剪枝操作, 当一次出现为true时就不用继续判断了
                    if(memo[i]) break;
                }
        return memo[s.size()-1];
    }
};