//
// Created by Daolin on 2019/9/10.
//

/**
 * 这里的解是通解, 参考了0092问题的思路,
 * 只要把n的值更改, 就可以解决反转三个元素? 反转四个元素? 等等
 * 在每次反转两个, 之后节点前进两位, 重复这个过程, 直到节点不足两个
 */

#include "ListNode.h"
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int n = 2;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(hasEnoughNode(cur->next, n)){
            cur->next = reverseNode(cur->next, n);
            for(int i = 0; i < n; i++)
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
