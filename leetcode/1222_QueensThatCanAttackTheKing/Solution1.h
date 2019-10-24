//
// Created by Daolin on 2019/10/13.
//
#include "../commonHeader.h"

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int dia1 = king[0] - king[1] + 8;
        int dia2 = king[0] + king[1];

        vector<vector<int>> res;

        for(auto& q : queens){
            int col = q[0];
            int row = q[1];
            int qDia1 = col - row + 8;
            int qDia2 = col + row;

            if(row == king[1] || col == king[0] || qDia1 == dia1 || qDia2 == dia2)
                res.push_back(q);
        }

        unordered_map<int, vector<int>> map;
        int n;
        for(auto& q : res){
            int temp;
            int d = dis(king, q, n);

            n --;
            if(map[n].size() == 0 || d < dis(king, map[n], temp))
                map[n] = q;
        }

        res.clear();
        for(auto& q : map)
            if(q.second.size() > 0)
                res.push_back(q.second);
        return res;
    }

    int dis(vector<int>& king, vector<int>& queen, int& n){

        if(king[0] == queen[0]){
            if(king[1] > queen[1])
                n = 1;
            else
                n = 5;
        }else if(king[1] == queen[1]){
            if(king[0] > queen[0])
                n = 7;
            else
                n = 3;
        }else if(king[0] > queen[0] && king[1] > queen[1])
            n = 6;
        else if(king[0] < queen[0] && king[1] > queen[1])
            n = 4;
        else if(king[0] > queen[0] && king[1] < queen[1])
            n = 2;
        else if(king[0] < queen[0] && king[1] < queen[1])
            n = 8;

        int a = king[0] - queen[0];
        int b = king[1] - queen[1];

        return a*a + b*b;
    }
};
