//
// Created by Daolin on 2019/9/9.
//
#include "ListNode.h"

/**
 * Solution1的简化版本,
 * 因为链表不需要一个一个赋值, 所以当 l1 , l2中有一个为空时,
 * 就可以直接把 tail->next 指向另一个
 *
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        ListNode* tmp;

        // 和归并排序很像
        while(l1 && l2){
            if(l1->val < l2->val){
                tmp = l1;
                l1 = l1->next;      // l1因为要移动所以原本的l1由tmp替代赋给tail->next
                tail->next = tmp;
                tail = tail->next;
            }else{
                tmp = l2;
                l2 = l2->next;
                tail->next = tmp;
                tail = tail->next;
            }
        }
        auto l3 = l1 ? l1 : l2;
        tail->next = l3;
        auto ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
