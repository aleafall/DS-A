//
// Created by aleafall on 17-2-18.
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
	ListNode *deleteDuplication(ListNode *pHead) {
		if (!pHead) {
			return NULL;
		}
		ListNode *pre = NULL, *p = pHead, *newHead = NULL;
		long long needDel = INT64_MIN;
		while (p) {
			if (p->val == needDel || p->next && p->val == p->next->val) {
				needDel = p->val;
				if (pre) {
					pre->next = p->next;
				}
			} else {
				if (!pre) {
					newHead = p;
				}
				pre = p;
			}
			p = p->next;
		}
		return newHead;
	}
};
