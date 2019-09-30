//
// Created by Daolin on 2019/9/27.
//
#include <vector>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:


    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for ( int h=0; h<=11; h++ ) {
            for ( int m=0; m<=59; m++ ) {
                // min can be upto 6 bits, so shift hour by 6 bits to keep bit sets in val
                int val = h<<6 | m;
                if ( num == bitset<10> (val).count() ) {
                    string out = to_string(h) + (m <10 ? ":0" : ":") + to_string(m) ;
                    res.push_back (out);
                }
            }
        }

        return res;
    }
};
