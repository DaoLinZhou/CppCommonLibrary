//
// Created by Daolin on 2019/11/23.
//
#include "../commonHeader.h"

class Solution {
public:
    vector<vector<unsigned long long>> memo;
    vector<int> d = {-1, 0, 1};
    int size;

    bool inArea(int i){
        return i >= 0 && i < size;
    }

    unsigned long long move(int steps, int index){
        if(steps == 0 && index == 0)
            return 1;
        if(steps == 0)
            return 0;
        if(memo[index][steps] != -1)
            return memo[index][steps];
        unsigned long long res = 0;
        for(int i = 0; i < d.size(); i++){
            int new_index = index + d[i];
            if(inArea(new_index))
                res += move(steps-1, new_index);
        }
        return memo[index][steps] = (res % 1000000007);
    }

    int numWays(int steps, int arrLen) {
        size = min(steps+1, arrLen);
        memo = vector<vector<unsigned long long>>(size, vector<unsigned long long>(steps+1, -1));
        return move(steps, 0);
    }
};
