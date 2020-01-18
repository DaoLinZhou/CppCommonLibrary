//
// Created by Daolin on 2020/1/17.
//
#include "../commonHeader.h"

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices % 2 || cheeseSlices*2 > tomatoSlices || cheeseSlices*4 < tomatoSlices)
            return {};
        tomatoSlices /= 2;
        return {tomatoSlices-cheeseSlices, 2*cheeseSlices-tomatoSlices};
    }
};
