//
// Created by Daolin on 2019/9/9.
//

#include "ListNode.h"

// 递归写法
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)     // 递归到底, 返回空
            return head;
        // 假设后面的都移除了
        head->next = removeElements(head->next, val);
        // 重点, 判断当前head是否需要被移除, 需要则返回next节点
        return head->val == val ? head->next : head;
    }
};
