//
// Created by Daolin on 2019/9/10.
//
#include <vector>
#include <algorithm>
#include "ListNode.h"
// 递归merge
// Time complexity O(nlogn)
// Space complexity O(logn)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        /// 把List截成两半
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;

        /// 递归
        head = sortList(head);
        head2 = sortList(head2);

        /// 归并
        return merge(head, head2);
    }

private:
    // merge 2 sorted list
    ListNode* merge(ListNode* l, ListNode* r){
        ListNode dummyHead(0);
        ListNode* tail = &dummyHead;
        while( l && r){
            if(l->val < r->val){
                tail->next = l;
                l = l->next;
            }else{
                tail->next = r;
                r = r->next;
            }
            tail = tail->next;
        }
        ListNode* remain = l ? l : r;
        tail->next = remain;
        return dummyHead.next;
    }
};