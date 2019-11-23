//
// Created by Daolin on 2019/11/22.
//
#include "../commonHeader.h"

class Solution {
public:

    char getSymbol(int n){
        switch (n){
            case 1:    return 'I';
            case 5:    return 'V';
            case 10:   return 'X';
            case 50:   return 'L';
            case 100:  return 'C';
            case 500:  return 'D';
            case 1000: return 'M';
            default:   return '?';
        }
    }

    string intToRoman(int num) {
        vector<int> record;
        while(num != 0){
            record.push_back(num%10);
            num /= 10;
        }
        string ret = "";
        for(int i = record.size()-1; i >= 0; i--){
            int n = pow(10, i);
            /// 三种可能的情况
            if(abs(record[i] - 5) == 1){
                if(record[i] == 4)
                    ret = ret + getSymbol(n) + getSymbol(5*n);
                else
                    ret = ret + getSymbol(5*n) + getSymbol(n);
            }
            else if(record[i] == 9){
                ret = ret + getSymbol(n) + getSymbol(10*n);
            }
            else{
                int b = record[i]/5;
                int s = record[i]%5;
                if(b) ret += getSymbol(5*n);
                char sym = getSymbol(n);
                for(int i = 0; i < s; i++)
                    ret += sym;
            }
        }
        return ret;
    }
};