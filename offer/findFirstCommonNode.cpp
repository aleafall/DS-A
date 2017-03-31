//
// Created by aleafall on 17-2-22.
//

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;

	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
		if (!pHead1 || !pHead2) {
			return NULL;
		}
		int n1 = 0, n2 = 0;
		ListNode *p = pHead1, *q = pHead2;
		while (p) {
			++n1;
			p = p->next;
		}
		while (q) {
			++n2;
			q = q->next;
		}
		p = pHead1, q = pHead2;
		if (n1 > n2) {
			for (int i = 0; i < n1 - n2; ++i) {
				p = p->next;
			}
		} else {
			for (int i = 0; i < n2 - n1; ++i) {
				q = q->next;
			}
		}
		while (p) {
			if (p == q) {
				return p;
			}
			p = p->next, q = q->next;
		}
		return NULL;
	}
};
