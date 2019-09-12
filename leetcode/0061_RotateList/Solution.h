//
// Created by Daolin on 2019/9/11.
//
#include "ListNode.h"
/**
 * 解题思路:
 * 遍历一遍链表, 记录最后的节点和总结点数
 * 把最后一个节点指向原先的头节点, 形成环
 *
 * 于是问题转化成 -> 应该在哪个位置断开这个环
 * k%i是右移的个数, 总长度为 i, 所以初始节点后 i-(k % i)-1 的位置就是新链表的尾节点,
 * 只要记录这个节点的下一个节点作为返回的头节点
 * 再把这个节点的next设置成空 (断开环), 即可
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) return head;    // 特殊处理
        ListNode* p = head;
        int i = 1;      // i应该从1开始, 因为我们已经计算head节点
        while(p->next){
            i++;
            p = p->next;
        }
        // p是原链表最后一个节点, 这一步形成环
        p->next = head;

        k = i - (k % i);
        // k个节点中有k-1条边, 所以走k-1次就能移到第k个节点
        for(int j = 0; j < k-1; j++)
            head = head->next;

        auto retHead = head->next;
        head->next = nullptr;   // 断开环
        return retHead;
    }
};
