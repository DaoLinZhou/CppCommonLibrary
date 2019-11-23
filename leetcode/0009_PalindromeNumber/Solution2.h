//
// Created by Daolin on 2019/11/17.
//

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x != 0 && x % 10 == 0)
            return false;
        if(x < 10)
            return true;

        int temp = x;
        long int newNum = 0;
        while(temp != 0){
            newNum = newNum*10 + temp%10;
            temp /= 10;
        }
        return newNum == x;
    }
};