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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head, *q = head, *pre;
        if (head == NULL || head->next == NULL)
            return NULL;
        while (n--) p = p->next;
        if (p == NULL) {
            pre = head;
            head = head->next;
            delete pre;
            return head;
        }
        while (p->next != NULL) {
            p = p->next;
            q = q->next;
        }
        pre = q->next;
        q->next = pre->next;
        delete pre;
        return head;

    }
};

int main() {
    Solution *solution = new Solution;
    ListNode *head = new ListNode(1);
    ListNode *ans = solution->removeNthFromEnd(head, 1);
    while (ans != NULL) {
        cout << ans->val << endl;
        ans = ans->next;
    }
    delete solution;
    return 0;
}