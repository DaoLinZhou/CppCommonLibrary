//
// Created by Daolin on 2019/9/10.
//

#include "ListNode.h"

/**
 * 解题思想:
 * 和普通的插入排序(从后向前找)不同, 由于没有指向前一个节点的指针,
 * 所以正确的方式应该是暂存头节点, 从前往后找
 */

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;      // 如果为空直接返回
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* first;            // 记录头部, 用来插入节点
        ListNode* tail = head;      // 记录尾部, 用来寻找节点
        while(tail->next){          // 每次比较当前节点和下一个节点, 所以必须保证下一个节点不为NULL
            if(tail->val > tail->next->val){
                first = dummyHead;  // 初始化头部
                auto node = tail->next;     // 我们要把node节点插入到前面的列表
                tail->next = tail->next->next;      // 先把node节点从链表删除
                while(first->next->val < node->val) // 寻找node应该插入位置的前一个节点
                    first = first->next;
                // 插入node
                node->next = first->next;
                first->next = node;
            }else{
                tail = tail->next;  // tail向后移动
            }
        }
        auto ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
