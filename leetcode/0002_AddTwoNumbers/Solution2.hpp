//
// Created by Daolin on 2019/12/3.
//

#include "../commonHeader.h"

/// 递归写法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }else if(l1 != nullptr && l2 == nullptr){
            return l1;
        }else if(l1 == nullptr && l2 != nullptr){
            return l2;
        }else{
            ListNode* l3;
            int num = l1->val + l2->val;
            if(num >= 10){
                l3 = new ListNode(num - 10);
                l3->next = addTwoNumbers(l1->next, addTwoNumbers(l2->next, new ListNode(1)));
            }else{
                l3 = new ListNode(num);
                l3->next = addTwoNumbers(l1->next, l2->next);
            }
            return l3;
        }
    }
};

