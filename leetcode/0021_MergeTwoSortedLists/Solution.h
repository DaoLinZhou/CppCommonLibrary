//
// Created by Daolin on 2019/9/9.
//
#include "ListNode.h"

/**
 * 解题思路:
 * 使用归并排序的思路即可
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        ListNode* tmp;

        // 和归并排序很像
        while(l1 || l2){
            if(!l1){
                tail->next = l2;
                l2 = nullptr;       // 停止遍历, 因为链表的特殊结构, l2后边所有节点也都移到tail上了
            }else if(!l2){
                tail->next = l1;
                l1 = nullptr;
            }else if(l1->val < l2->val){
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
        auto ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};