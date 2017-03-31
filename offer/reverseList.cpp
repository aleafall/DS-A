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
	ListNode *ReverseList(ListNode *pHead) {
		if (!pHead) {
			return pHead;
		}
		ListNode *p = pHead;
		ListNode *ans = new ListNode(0);
		while (p) {
			ListNode *q = p;
			p = p->next;
			q->next = ans->next;
			ans->next = q;

		}
		return ans->next;
	}
};

int main(){
	ListNode *node[10];
	for (int i = 0; i < 10; ++i) {
		node[i] = new ListNode(i);
		if (i) {
			node[i - 1]->next = node[i];
		}
	}
	Solution solution;
	ListNode *pHead = node[0];
	pHead = solution.ReverseList(pHead);
	int i = 0;
	while (pHead) {
		if (++i > 100) {
			break;
		}
		cout << pHead->val << " ";
		pHead = pHead->next;
	}
	for (int i = 0; i < 10; ++i) {
		delete node[i];
	}
}
