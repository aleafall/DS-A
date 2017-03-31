//
// Created by aleafall on 17-2-7.
//

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *removeElements(ListNode *head, int val) {
		if (!head) {
			return NULL;
		}
		ListNode *newHead = NULL, *pre = NULL, *p = head;
		while (p) {
			if (p->val != val) {
				if (!newHead) {
					newHead = p;
				}
				if (pre) {
					pre->next = p;
				}
				pre = p;
			}
			p = p->next;
		}
		if (pre) {
			pre->next = NULL;
		}
		return newHead;
	}
};