//
// Created by Daolin on 2019/9/11.
//

#include "ListNode.h"

/**
 * 解题思想:
 * 由于我们无法获取当前节点的前一个节点, 所以我们不能删除当前节点,
 * 但是我们可以把下一个节点的值拷贝到当前节点, 之后移除下一个节点
 * 虽然链表题一般不希望通过改变值来操作节点, 但对于一些特殊题目, 要脑子灵活
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node) return;
        if(!node->next) delete node;    // 如果后面没有节点, 直接delete

        ListNode* delNode = node->next;
        node->val = node->next->val;    // 拷贝值
        node->next = node->next->next;  // 指针指向下下个节点

        delete delNode;     // 删除节点
        return;
    }
};
