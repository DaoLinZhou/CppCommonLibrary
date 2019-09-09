//
// Created by Daolin on 2019/9/8.
//

#include "ListNode.h"
/**
 * 解题思路:
 * 结合 0002 号问题, 和 0206 号问题的解法,
 * 先把 l1,l2 反转成满足 0002 条件的链表,
 * 用 0002 的方法相加, 把结果在进行反转
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return reverseList(_addTwoNumbers(reverseList(l1), reverseList(l2)));
    }

private:
    ListNode* reverseList(ListNode* head) {
        _reverseList(head);
        return newHead;
    }

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

    ListNode* _addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);   // 虚拟头节点
        bool flag = false;                  // 是否有过进位
        ListNode* tail = head;              // 在尾部添加新节点
        while(l1 || l2 || flag){
            int l1num = l1 ? l1->val : 0;
            int l2num = l2 ? l2->val : 0;
            int num = flag ? 1 + l1num + l2num : l1num + l2num;
            if(num >= 10){
                num = num-10;   // 加法不可能超过20
                flag = true;
            }else
                flag = false;
            tail->next = new ListNode(num);
            tail = tail->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return head->next;
    }
};
