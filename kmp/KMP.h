//
// Created by jiatang on 2022/7/2.
//

#ifndef CPPCOMMONLIBRARY_KMP_H
#define CPPCOMMONLIBRARY_KMP_H

#include "../leetcode/commonHeader.h"

class KMP {
public:
    void get_next_arr(const string& subStr, vector<int>& next){
        int i = 1, j = 0, prefix_len = 0;

        next[0] = 0;
        while (i < subStr.length()){
            if(subStr[prefix_len] == subStr[i]){
                prefix_len ++;
                j ++;
                next[j] = prefix_len;
                i ++;
            } else {
                if (prefix_len == 0) {
                    j++;
                    next[j] = 0;
                    i++;
                } else {
                    prefix_len = next[prefix_len - 1];
                }
            }
        }
    }

    void get_next_arr_2(const string& subStr, vector<int>& next) {

        assert(next.size() == subStr.length());
        int i = 1;
        int next_idx = 1;
        int prefix_len = 0;

        next[0] = 0;
        while(i < subStr.length()){
            if(subStr[prefix_len] == subStr[i]){
                prefix_len ++;
                next[next_idx] = prefix_len;
                next_idx ++;
                i ++;
            }else{
                if(prefix_len == 0){
                    i ++;
                    next[next_idx] = 0;
                    next_idx ++;
                }else{
                    prefix_len = next[prefix_len - 1];
                }
            }
        }

    }

    int search(const string& str, const string& subStr){
        vector<int> next(subStr.length());
        this->get_next_arr_2(subStr, next);

        int i = 0;          // index in original string
        int j = 0;          // index in substring

        while(i < str.length()){
            if(str[i] == subStr[j]){
                i++;
                j++;
            }
            else if(j > 0){
                j = next[j - 1];
            }
            else{
                i++;
            }

            if(j == subStr.length()){
                return i - j;
            }
        }

        return -1;
    }
};


#endif //CPPCOMMONLIBRARY_KMP_H
