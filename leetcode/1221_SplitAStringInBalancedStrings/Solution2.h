//
// Created by Daolin on 2019/10/13.
//
#include "../commonHeader.h"

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        /// [j ... i]
        vector<int> vec = vector(2, 0);
        int j = 0;
        for(int i = 0; i < s.size(); i++){

            if(s[i] == 'L')
                vec[0] ++;
            else
                vec[1] ++;

            if(i != j && vec[0] == vec[1]){
                count ++;
                j = i+1;
            }
        }
        return count;
    }
};

