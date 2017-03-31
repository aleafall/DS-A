//
// Created by aleafall on 16-10-20.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *pre = NULL, *now = head, *newHead = NULL;
        int needDel = INT32_MIN;
        while (now) {
            if (now->val == needDel || now->next && now->val == now->next->val) {
                needDel = now->val;
                if (pre) pre->next = now->next;
            } else {
                if (!pre) newHead = now;
                pre = now;
            }
            now = now->next;
        }
        return newHead;
    }
};

int main() {
    Solution *solution = new Solution;
    ListNode *node[7];
    node[0] = new ListNode(1);
    node[1] = new ListNode(2);
    node[2] = new ListNode(3);
    node[3] = new ListNode(3);
    node[4] = new ListNode(4);
    node[5] = new ListNode(4);
    node[6] = new ListNode(5);

}
