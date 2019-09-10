//
// Created by Daolin on 2019/9/9.
//

#include "ListNode.h"
/**
 * 解题思路:
 * 如果当前元素的下一个元素的val和我们要删除的val相等, 就把当前元素指向下下个元素
 * 由于第一个元素可能也是要删除的元素, 所以设立虚拟头节点
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next){
            if(cur->next->val == val) {
                ListNode *delNode = cur->next;
                cur->next = delNode->next;    // 指向下下个节点, cur不动
                // 删除要删除的节点, 算法解题虽然可以不删但为了培养好习惯, 以及程序的健壮性
                delete delNode;
            } else
                cur = cur->next;
        }
        return dummyHead->next;
    }
};
