//
// Created by Daolin on 2019/9/8.
//

#include "ListNode.h"
/**
 * 解题思路:
 * 判断下一个节点个当前节点是否相等, 如果相等, 就把cur->next指向下下个节点
 *      注意1 : 如果下一个节点为空则一定不等
 *      注意2 : 如果执行了 cur->next指向下下个节点, 此时next已经改变, 应该重新判断是否相等, 而不应该移动当前节点到next
 * 如果不等则移动当前节点到next
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* next;
        while(cur){
            next = cur->next;
            if(next != nullptr && next->val == cur->val)
                cur->next = next->next;
            else        // 当cur->next发生改变时, cur不应该改变位置, 应该在与next进行判断
                cur = cur->next;
        }
        return head;
    }
};
