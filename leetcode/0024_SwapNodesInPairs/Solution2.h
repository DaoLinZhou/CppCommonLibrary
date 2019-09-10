//
// Created by Daolin on 2019/9/10.
//
#include "ListNode.h"
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        while(p->next && p->next->next){
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;

            node2->next = node1;
            node1->next = next;
            p->next = node2;

            // 此时node1已经交换了位置, 所以此时node1是下一次交换节点之前的节点
            p = node1;
        }
        auto ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
