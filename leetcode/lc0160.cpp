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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
        ListNode *p=headA,*q=headB;
        while (p) {
            len1++;
            p=p->next;
        }
        while (q) {
            len2++;
            q=q->next;
        }
        if (len1 == 0 || len2 == 0) {
            return NULL;
        }
        p=headA,q=headB;
        int diff = abs(len1 - len2);
        if (len1 > len2) {
            while (diff--) {
                p=p->next;
            }
        } else if (len1 < len2) {
            while (diff--) {
                q=q->next;
            }
        }
        while (p) {
            if (p == q) {
                return p;
            }
            p=p->next;
            q=q->next;
        }
        return NULL;
    }
};
