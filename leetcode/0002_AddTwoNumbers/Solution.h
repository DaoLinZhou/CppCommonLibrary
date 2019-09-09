//
// Created by Daolin on 2019/9/8.
//

#include "ListNode.h"
/**
 * 解题思路:
 * 中规中矩, 遇到要进位的就计算进位后的值,
 * 不断添加新值到尾部
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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
