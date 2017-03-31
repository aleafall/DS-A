//
// Created by aleafall on 17-2-17.
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
	ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
		if (!pHead1) {
			return pHead2;
		}
		if (!pHead2) {
			return pHead1;
		}
		ListNode *ans;
		if (pHead1->val < pHead2->val) {
			ans=pHead1;
			ans->next = Merge(pHead1->next, pHead2);
		} else {
			ans = pHead2;
			ans->next = Merge(pHead1, pHead2->next);
		}
		return ans;
	}
};
