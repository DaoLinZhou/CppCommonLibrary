//
// Created by Daolin on 2019/9/10.
//
#include "ListNode.h"

/**
 * 代码和 0024 Solution1基本一样, 就是把n换位k
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(hasEnoughNode(cur->next, k)){
            cur->next = reverseNode(cur->next, k);
            for(int i = 0; i < k; i++)
                cur = cur->next;
        }
        auto ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }

private:
    bool hasEnoughNode(ListNode* node, int n){
        for(int i = 0; i < n; i ++){
            if(!node)
                return false;
            node = node->next;
        }
        return true;
    }

    // Assume n is valid
    // reverse first n node in a node list
    ListNode* reverseNode(ListNode* node, int n){
        ListNode* first = node;
        ListNode* pre = NULL;
        ListNode* cur = node;
        ListNode* next;
        for(int i = 0; i < n; i++){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        first->next = cur;
        return pre;
    }
};
