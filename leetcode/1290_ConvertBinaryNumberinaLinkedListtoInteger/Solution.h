//
// Created by Daolin on 2020/1/17.
//

#include "../commonHeader.h"

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> stack;
        while(head){
            stack.push_back(head->val);
            head = head->next;
        }

        int n = 1;
        int res = 0;

        for(int i = stack.size()-1; i >= 0; i--, n *= 2){
            if(stack[i] == 1)
                res += n;
        }
        return res;
    }
};

