//
// Created by Daolin on 2019/9/8.
//

#include "ListNode.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        auto odds = new ListNode(0);
        ListNode* ret1 = odds;
        auto * evens = new ListNode(0);
        ListNode* ret2 = evens;

        ListNode* cur = head;
        bool isOdd = true;
        while(cur){
            if(isOdd){
                odds->next = cur;
                odds = odds->next;
            }else{
                evens->next = cur;
                evens = evens->next;
            }
            isOdd = !isOdd;
            cur = cur->next;
        }
        evens->next = nullptr;
        odds->next = ret2->next;
        return ret1->next;
    }
};
