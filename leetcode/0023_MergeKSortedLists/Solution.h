//
// Created by Daolin on 2019/9/17.
//

#include <vector>
#include <queue>
#include "ListNode.h"
#include <functional>

/**
 * 解题思路:
 * 使用优先队列, 寻找有最小val的node, 取出后把它的next加入队列中
 *
 */

bool comNode(ListNode* node1, ListNode* node2){
    return node1->val > node2->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummyHead(0);
        ListNode* tail = &dummyHead;

        // 传入自己的比较函数
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(comNode);

        // 先把所有list的头节点放入队列
        for(ListNode* node : lists)
            if(node)
                pq.push(node);

        while(!pq.empty()){
            ListNode* cur = pq.top();
            pq.pop();

            tail->next = cur;
            tail = tail->next;

            // 有可能为空
            if(cur->next)
                pq.push(cur->next);
        }

        return dummyHead.next;
    }
};
