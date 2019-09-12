//
// Created by Daolin on 2019/9/11.
//
#include "ListNode.h"

/**
 * 解题思想:
 * 把原链表拆分为两个等长部分(或者第二个链表比第一个链表多一个元素)
 * 反转第二个链表, 与第一个链表交叉合并
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode* slow = head;
        ListNode* fast = head->next;

        /// 如果总节点数为9, fast会走到10, slow会走到5, 6是后半链表的头节点
        /// 如果总结点树为8, fast会走到8, slow会走到4, 5是后半链表的头节点
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;           // 断开前半链表和后半链表
        head2 = recursiveReverse(head2);    // 反转后半链表

        ListNode* indexNode = head;
        while(head2){
            ListNode* nnext = indexNode->next;      // 注意这里一定要暂存next
            indexNode->next = head2;                // 合并head2节点
            head2 = head2->next;                    // head2移动
            indexNode->next->next = nnext;          // 要把下下个元素重新指向暂存的next, 不然会是死循环
            indexNode = nnext;                      // 如果上面不指回原本的next节点, indexNode前进两步就会走到head2那条链表上
        }
    }

private:
    // 第一种reverse方法, 循环
    ListNode* reverseLinkedList(ListNode* node){
        ListNode* pre = NULL;
        ListNode* cur = node;
        ListNode* next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }


    // 第二种reverse方法, 递归
    ListNode* retHead;
    ListNode* recursiveReverse(ListNode* head){
        // 注意这里返回的是尾节点, 而真正要返回的是retHead
        _recursiveReverse(head);
        return retHead;
    }

    ListNode* _recursiveReverse(ListNode* node){
        if(!node || !node->next){
            retHead = node;
            return retHead;
        }
        ListNode* tmp = node;
        ListNode* tail = _recursiveReverse(node->next);
        node->next = nullptr;
        return tail->next = node;
    }
};