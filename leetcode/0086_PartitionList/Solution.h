//
// Created by Daolin on 2019/9/8.
//

#include "ListNode.h"

/**
 * 题外话:
 *      最开始解这道题的时候想着直接在原始链表上解决, 但实现起来太过复杂, 有很多坑
 *      一直没解出来, 后来看到solution的介绍才有思路, 于是写出下面代码,
 *      并不难, 一次提交就成功通过, 但如果没有思路可能会卡很久
 * 解题思路:
 *      新建两个列表, 一个存储小于x的节点, 一个存储大于等于x的节点
 *      遍历原始列表, 分配当前节点到两个列表中
 *      最后要记得把after的最后一个节点指空, 避免产生环
 *
 *      最后的最后把两个列表拼接到一起并返回
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* before = new ListNode(0);
        ListNode* retHead1 = before;    // 记录before列表头
        ListNode* after = new ListNode(0);
        ListNode* retHead2 = after;     // 记录after列表头

        ListNode* cur = head;
        while(cur){
            if(cur->val < x){
                before->next = cur;
                before = before->next;
            }else{
                after->next = cur;
                after = after->next;
            }
            cur = cur->next;
        }
        after->next = nullptr;          // 防止产生环
        before->next = retHead2->next;  // before列表尾指向after列表头
        return retHead1->next;          // 省略dummyHead
    }
};