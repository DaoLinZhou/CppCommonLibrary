//
// Created by Daolin on 2019/9/11.
//

#include "ListNode.h"

/**
 * 解题思路:
 * 设置全局变量记录倒数元素的位置
 * 递归到底后每往上返回一层, index就 +1
 * 如果index == n, 说明当前元素是我们要删除的元素, 返回当前元素的下一个节点
 * 否则返回当前元素
 *
 * 注意: 这里没有delete掉要删除的节点, 因为这样代码显得不太美观,
 * 所以这个解法更适合与有垃圾回收机制的语言
 */

class Solution {
public:

    int index = 1;

    // 递归解法
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 本题n >= 1所以链表至少有一个元素, head必定不为空, 但这里只是为了程序容错性更高, 对head判一下空
        if(!head || !head->next)
            return index++ == n ? nullptr : head;
        head->next = removeNthFromEnd(head->next, n);
        return index++ == n ? head->next : head;
    }
};
