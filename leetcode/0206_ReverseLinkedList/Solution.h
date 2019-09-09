//
// Created by Daolin on 2019/9/7.
//
#include "ListNode.h"

// 递归解法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        _reverseList(head);
        return newHead;
    }
private:
    ListNode* newHead;
    ListNode* _reverseList(ListNode* head) {
        if(!head || !head->next){   // 如果head为空, 或者head是最后一个node
            newHead = head;         // 暂时保存新的head
            return head;            // 返回tail, 由于是最后一个node, head和tail是同一个node
        }
        ListNode* node = head;      // 暂存当前node
        ListNode* tail = _reverseList(head->next);  // 取得剩余部分反转后的tail节点
        node->next = nullptr;       // 避免链表变成环
        return tail->next = node;   // 当前node连接到tail上
    }
};