//
// Created by Daolin on 2019/9/8.
//

/**
 * 挑战:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 * 在不改变链表, 不反转链表的情况下解题
 *
 * 解题思路:
 * 辅助数据结构 stack
 *
 */
#include <stack>
#include "../0002_AddTwoNumbers/ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> s1, s2;
        while (l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* node = nullptr;
        ListNode* newNode;
        bool flag = false;
        while(!s1.empty() && !s2.empty()){
            int i = s1.top() + s2.top() + flag;
            s1.pop(); s2.pop();
            if(i >= 10){
                i = i - 10;
                flag = true;
            } else
                flag = false;
            newNode = new ListNode(i);
            newNode->next = node;
            node = newNode;
        }
        // 此时有一个肯定为空, 所以我们只需要专注另一个stack
        stack<int>& s3 = s1.empty() ? s2 : s1;
        while(!s3.empty()){
            int i = s3.top() + flag;
            s3.pop();
            if(i >= 10){
                i = i - 10;
                flag = true;
            } else
                flag = false;
            newNode = new ListNode(i);
            newNode->next = node;
            node = newNode;
        }
        // 最后如果进位
        if(flag){
            newNode = new ListNode(1);
            newNode->next = node;
            node = newNode;
        }
        return node;
    }
};

