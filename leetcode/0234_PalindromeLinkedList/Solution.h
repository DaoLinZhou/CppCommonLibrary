//
// Created by Daolin on 2019/9/11.
//

#include "ListNode.h"

/// 提升测试速度
auto optimize_cpp_stdio = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
    return 0;
}();

/**
 * 解题思路:
 * 先把链表拆分为两个等长部分,
 * 反转第二个链表
 * 与第一个链表进行对比, 如果发现不同则返回false
 * 到最后都一样则返回 true
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head->next;

        /// 如果总节点数为9, fast会走到10, slow会走到5, 6是后半链表的头节点
        /// 如果总结点树为8, fast会走到8, slow会走到4, 5是后半链表的头节点
        /// 所以 head链表的长度 大于等于 head2链表的长度
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;       /// 断开两个链表

        /// 反转第二个链表
        head2 = reverseLinkedList(head2);

        /// head2是较短(可能)的那个链表,
        /// 如果两个链表长度不等, 说明有奇数个节点, 中间的那个节点不用考虑
        while (head2){
            if(head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }

private:
    ListNode* reverseLinkedList(ListNode* node){
        ListNode* pre = NULL;
        ListNode* cur = node;
        ListNode* next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
