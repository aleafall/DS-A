//
// Created by aleafall on 16-11-7.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        ListNode *p=l1,*q=l2,*r;
        ListNode *newHead = new ListNode(0);
        r=newHead;
        while (p && q) {
            if (p->val < q->val) {
                r->next=p;
                r=r->next;
                p=p->next;
            } else {
                r->next=q;
                r=r->next;
                q=q->next;
            }
        }
        if (p) {
            r->next=p;
        }
        if (q) {
            r->next=q;
        }
        return newHead->next;
    }
};
