//
// Created by Daolin on 2019/9/14.
//
#include <string>
#include <unordered_map>

using namespace std;

/**
 * 把所有字符放入map, 分别查看 balloon 每个char出现次数
 * 出现最少的就是return值, 注意 l 和 o出现两次, 所以计算可用次数时应该除以2
 */

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> map;
        for(char c : text)
            map[c] ++;
        int arr[5] = {0};
        arr[0] = map['b'];
        arr[1] = map['a'];
        arr[2] = map['l']/2;
        arr[3] = map['o']/2;
        arr[4] = map['n'];

        int min = arr[0];
        for(int i : arr)
            if(i < min)
                min = i;
        return min;
    }
};
