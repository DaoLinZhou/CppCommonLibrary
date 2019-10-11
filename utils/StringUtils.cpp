//
// Created by Daolin on 2019/9/12.
//

#include "StringUtils.h"

std::vector<std::string> StringUtils::split(std::string s, char c){
    int first = 0;
    std::vector<std::string> ret;
    std::string item = "";
    for(int i = 0; i < s.length(); i ++){
        // 把[first...i)这个位置的字符串添加进vec, 之后first = i+1 跳过分割符继续
        if(s[i] == c){
            while(first < i) item += s[first++];
            first ++;
            if(item != "") {
                ret.push_back(item);
                item = "";
            }
        }
    }
    // 处理最后那一段, 因为最后可能不是以分割符结尾
    while (first < s.length()) item += s[first++];
    if(item != "")
        ret.push_back(item);
    return ret;
}

