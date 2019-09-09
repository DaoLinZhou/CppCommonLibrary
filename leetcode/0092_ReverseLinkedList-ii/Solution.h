//
// Created by Daolin on 2019/9/8.
//
#include "ListNode.h"
/**
 * 解题思路:
 * 首先找到要开始反转的前一个节点,
 * 把这个节点的下一个元素指向反转后的第一个节点
 *
 * 反转函数, 从头开始, 反转到第n个节点
 *
 * 为什么要用dummyHead?
 * 正常情况下( m > 1 ), head这个节点就是我们要返回的节点
 * 但当 m == 1时, head也参与到反转, 此时不应该返回head,
 * 既然如此, 就建立一个虚拟头节点, 所有操作都是基于虚拟头节点
 * 最终返回时, 返回它的next节点就好了
 */

class Solution{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 为了统一程序的执行, 使用虚拟头结点, 因为如果m从1开始, 那么当前的头节点就不是我们想要返回的头节点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        // 找到m节点的前一个节点, 由于有头节点, 所以要走m-1次
        for(int i=0; i < m-1; i++)
            pre = pre->next;
        if(pre->next != nullptr)    // 有可能下一个节点为NULL
            pre->next = reverse(pre->next, n - m + 1);
        return dummyHead->next;     // 返回时去掉头节点
    }

private:
    // reverse list start from node, n nodes total
    ListNode* reverse(ListNode* node, int n){
        ListNode* pre = NULL;
        ListNode* cur = node;
        ListNode* next;

        // 记录反转后的最后一位
        ListNode* tmp = cur;

        // 走第n次时, cur指向n+1的位置
        for(int i=0; cur && i < n; i++){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // 把反转后的最后一位指向剩余没被反转的第一个节点
        tmp->next = cur;
        return pre; // 返回反转后的头节点
    }
};

