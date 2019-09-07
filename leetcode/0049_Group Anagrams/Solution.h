//
// Created by Daolin on 2019/9/5.
//

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        // category string是排好序后的字符串, int代表和这个字符串互为Anagram的字符串group在ret中的位置
        unordered_map<string, int> category;
        // 遍历所有字符串
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());

            // 如果查找表中有这个元素
            if(category.find(sortedStr) != category.end()){
                // 放入ret的指定group中
                ret[category[sortedStr]].push_back(s);
            }else{
                // 新建一个group放入ret
                ret.push_back({s});
                // category中记录sortedStr的Anagram字符串在ret中应该放入的位置
                category[sortedStr] = static_cast<int>(ret.size() - 1);
            }
        }
        return ret;
    }
};
