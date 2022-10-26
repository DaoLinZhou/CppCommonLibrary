//
// Created by jiatang on 2022/7/29.
//

#ifndef CPPCOMMONLIBRARY_SOLUTION_H
#define CPPCOMMONLIBRARY_SOLUTION_H

#include "../commonHeader.h"

// 简单 dp

class Solution {
public:


    int minCostClimbingStairs(vector<int>& cost) {

        int* pc = new int[cost.size()+1];
        pc[0] = 0;
        pc[1] = 0;
        for(int i=2; i<=cost.size(); i++){
            pc[i] = min(pc[i-1] + cost[i-1], pc[i-2]+cost[i-2]);
        }
        return pc[cost.size()];
    }

};

#endif //CPPCOMMONLIBRARY_SOLUTION_H
