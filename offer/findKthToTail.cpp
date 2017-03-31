//
// Created by aleafall on 17-2-24.
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
	ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
		if (!pListHead) {
			return NULL;
		}
		ListNode *fast = pListHead, *slow = pListHead;
		for (int i = 0; i < k; ++i) {
			if (!fast) {
				return NULL;
			}
			fast = fast->next;
		}
		while (fast) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};
