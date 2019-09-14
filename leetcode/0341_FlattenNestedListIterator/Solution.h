//
// Created by Daolin on 2019/9/14.
//

#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector <NestedInteger> &getList() const;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


class NestedIterator {
public:
    stack <NestedInteger> stack1;
    stack<int> stack2;

    NestedIterator(vector <NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); i++)
            stack1.push(nestedList[i]);
        while (!stack1.empty()) {
            NestedInteger top = stack1.top();
            stack1.pop();
            if (top.isInteger())
                stack2.push(top.getInteger());
            else {
                auto list = top.getList();
                for (int i = 0; i < list.size(); i++)
                    stack1.push(list[i]);
            }
        }
    }

    int next() {
        int next = stack2.top();
        stack2.pop();
        return next;
    }

    bool hasNext() {
        return !stack2.empty();
    }
};

