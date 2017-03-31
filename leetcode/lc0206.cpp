//
// Created by aleafall on 16-10-6.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *ans, *pre;
        ans->next = NULL;
        while (head != NULL) {
            ListNode *node = new ListNode(head->val);
            node->next = ans->next;
            ans->next = node;
            pre = head;
            head = head->next;
            delete pre;
        }
        return ans->next;
    }
};
