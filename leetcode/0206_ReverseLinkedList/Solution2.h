//
// Created by Daolin on 2019/9/7.
//
#include "ListNode.h"


// 循环解法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next;     // next 依赖于cur, 所以next具体赋值是在循环里
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // 此时cur是NULL, 而pre才是最后一个指针
        return pre;
    }
};

