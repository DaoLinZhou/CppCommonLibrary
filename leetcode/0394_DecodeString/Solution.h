//
// Created by Daolin on 2020/8/4.
//
#include "../commonHeader.h"

class Solution {
public:
    string decodeString(string s) {
        vector<char> vec;

        for(int i = 0; i < s.length(); i++){
            if(s[i] != ']'){
                vec.push_back(s[i]);
            }else{
                vector<char> charvec;
                while(vec[vec.size()-1] != '['){
                    charvec.push_back(vec[vec.size()-1]);
                    vec.pop_back();
                }
                vec.pop_back();

                // 获取重复次数
                int j = 1, count = 0;
                while(!vec.empty() && isnumber(vec[vec.size()-1])){
                    int n = vec[vec.size()-1] - '0';
                    vec.pop_back();
                    count += n*j;
                    j *= 10;
                }

                for(int k = 0; k < count; k++){
                    for(int n = charvec.size()-1; n >= 0; n--){
                        vec.push_back(charvec[n]);
                    }
                }
            }
        }
        stringstream ss;
        for(char& c: vec){
            ss << c;
        }
        return ss.str();

    }

    bool isnumber(char c){
        return c >= '0' && c <= '9';
    }
};
