//
// Created by Daolin on 2019/9/11.
//

#include <cassert>
#include "ListNode.h"
/**
 * 解题思路:
 * 倒数第n+1个节点和最后一个节点的后一个节点(NULL) 的距离(dis)是固定的
 * 于是我们可以声明两个指针, (p)一个指向当前节点, (q)另一个指向距离当前节点有dis距离的节点
 * 同时推动两个指针, 如果q指向空, 说明p指向倒数第n+1个节点, 于是我们就可以删除p的下一个节点
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(n >= 0);
        ListNode dummyHead(0);
        dummyHead.next = head;

        ListNode* p = &dummyHead;
        ListNode* q = &dummyHead;

        for (int i = 0; i < n + 1; ++i) {
            assert( q );
            q = q->next;
        }

        while(q){
            p = p->next;
            q = q->next;
        }
        ListNode* delNode = p->next;
        p->next = p->next->next;
        delete delNode;

        return dummyHead.next;
    }
};