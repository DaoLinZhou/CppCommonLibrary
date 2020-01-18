//
// Created by Daolin on 2020/1/17.
//
#include "../commonHeader.h"

class Solution {
public:
    int countDigits(int n){
        int ret = 0;
        do{
            ++ ret;
            n /= 10;
        } while (n > 0);
        return ret;
    }

    bool isSequentialDigits(int n){
        int pre = n % 10 + 1;
        while(n > 0){
            int cur = n % 10;
            if(cur + 1 != pre)
                return false;
            pre = cur;
            n /= 10;
        }
        return true;
    }

    void createNum(int digits, vector<int>& vec){
        int dis = 1;
        int min = 1;
        for(int i = 1, next = 2; i < digits; i++, next ++){
            dis *= 10;
            dis += 1;
            min *= 10;
            min += next;
        }
        int max = 9 * dis;

        while(min < max){
            vec.push_back(min);
            min += dis;
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        int d1 = countDigits(low);
        int d2 = countDigits(high);

        vector<int> allResult;
        for(int i = d1; i <= min(d2, 9); i++){
            createNum(i, allResult);
        }

        vector<int> ans;
        for(int& i : allResult)
            if(low <= i && i <= high && isSequentialDigits(i))
                ans.push_back(i);
        return ans;
    }
};
