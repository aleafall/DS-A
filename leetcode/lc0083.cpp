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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
	    ListNode *pre = NULL, *p = head;
	    while (p) {
		    if (pre && pre->val == p->val) {
			    pre->next = p->next;
		    } else {
			    pre = p;
		    }
		    p = p->next;
	    }
	   /*
        ListNode *newHead=head,*p=head,*q=head;
        while (p) {
            if (p->val != q->val) {
                q->next=p;
                q=q->next;
            }
            p=p->next;
        }
        q->next=NULL;
        return newHead;
        */
	    return head;
    }
};
