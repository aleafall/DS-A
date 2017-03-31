//
// Created by aleafall on 16-10-17.
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
    ListNode *insertionSortList(ListNode *head) {
        if (head==NULL) return NULL;
        ListNode *newHead = NULL, *p = head, *q = NULL;
        while (p) {
            ListNode *temp = p->next;
            if (newHead) {
                q = newHead;
                while (q->next && q->val <= p->val) {
                    q = q->next;
                }
                    p->next = q->next;
                    q->next = p;
                if (q->val > p->val) {
                    swap(p->val, q->val);
                }
            } else {
                newHead=p;
                newHead->next = NULL;
            }
            p = temp;
        }
        return newHead;
    }
};
