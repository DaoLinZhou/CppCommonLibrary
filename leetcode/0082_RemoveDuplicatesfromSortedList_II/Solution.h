//
// Created by Daolin on 2019/9/9.
//
#include "ListNode.h"
/**
 * 解题思路:
 * 如果下一个节点和当前节点val相等, 则循环找到下一个不等的元素, 记为next
 * 当前节点同样不能要, 所以pre->next 指向next, 而cur就是next
 *
 * 如果不等则cur和pre都向前走一步 pre = cur, cur = next
 *
 *
 *
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        ListNode* cur = head;
        ListNode* next;

        while(cur){
            next = cur->next;
            if(next && next->val == cur->val){      // 一定要事先判断next是否为空, 避免空指针
                while(next && next->val == cur->val) {    // 找到下一个val和cur->val不等的节点, 或者找到NULL
                    auto nnext = next->next;
                    delete next;                    // 删除当前不要的节点
                    next = nnext;
                }
                delete cur;
                pre->next = next;                   // cur也同时不能要
            }else {
                pre = cur;
            }
            cur = next;
        }
        auto ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
