
//
// Created by Daolin on 2019/9/25.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        restoreIpAddressesHelper(s, 0, 4, "");  // 由于以.开始, 所以point要比预计的多一个, 即4个"."
        return res;
    }

private:
    vector<string> res;
    void restoreIpAddressesHelper(const string& sOrigin, const int& index, const int& points, string s){
        if(index >= sOrigin.size() && points == 0){
            res.push_back(s.substr(1));     // 最开始是".", 而我们不需要它
            return;
        }else if(index >= sOrigin.size() && points > 0){       // 还有.剩余
            return;
        }else if(index < sOrigin.size() && points <= 0){        // 还有字符串, 但没有.了
            return;
        } else{
//            // 往下走一位的情况
//            char num1 = sOrigin[index];
//            restoreIpAddressesHelper(sOrigin, index+1, points-1, s+"."+num1);
//
//            // 走两位的情况
//            if(index + 1 < sOrigin.size()){
//                string num2str = sOrigin.substr(index, 2);
//                int num2 = stoi(num2str);
//                if(num2 >= 10)
//                    restoreIpAddressesHelper(sOrigin, index+2, points-1, s+"."+num2str);
//            }
//
//            // 走三位的情况
//            if(index + 2 < sOrigin.size()){
//                string num3str = sOrigin.substr(index, 3);
//                int num3 = stoi(num3str);
//                if(num3 <= 255 && num3 >= 100)
//                    restoreIpAddressesHelper(sOrigin, index + 3, points - 1, s+"."+num3str);
//            }

            // 遍历执行 1, 2, 3步
            for(int j = 0; j < 3 && index + j < sOrigin.size(); j++){
                string numStr = sOrigin.substr(index, j+1);
                if(numStr.size() > 1 && numStr[0] == '0') break;
                int num = stoi(numStr);
                if(num > 255) break;
                restoreIpAddressesHelper(sOrigin, index + j + 1, points - 1, s+"."+numStr);
            }

        }
    }
};
