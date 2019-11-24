//
// Created by Daolin on 2019/11/23.
//

#include "../commonHeader.h"

class Solution {
public:

    bool hasPrefix(string& a, const string& b){
        if(b.size() > a.size())
            return false;
        return a.substr(0, b.size()) == b;
    }

    void search(vector<string>& products, const string& searchWord, vector<vector<string>>& res){
        for(string& s : products){
            if(res.back().size() == 3)
                return;
            if(hasPrefix(s, searchWord)){
                res.back().push_back(s);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        string w;
        for(char& c : searchWord){
            res.push_back({});
            w += c;
            search(products, w, res);
        }
        return res;
    }
};
