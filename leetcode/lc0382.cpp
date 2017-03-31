//
// Created by aleafall on 17-2-28.
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
	long long size;
	ListNode *pHead;
	/** @param head The linked list's head.
		Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode *head) {
		ListNode *p = head;
		pHead = head;
		size = 0;
		while (p) {
			++size;
			p = p->next;
		}
	}

	/** Returns a random node's value. */
	int getRandom() {
		if (!size) {
			return 0;
		}
		long long index = random() % size;
		ListNode *p = pHead;
		while (p) {
			if (!index) {
				return p->val;
			}
			p = p->next;
			--index;
		}
		return 0;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
