//
// Created by Daolin on 2019/9/12.
//

#include "StringUtils.h"

std::vector<std::string> StringUtils::split(std::string s, char c){
    int first = 0;
    std::vector<std::string> ret;
    std::string item = "";
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

