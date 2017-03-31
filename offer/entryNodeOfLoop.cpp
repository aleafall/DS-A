//
// Created by aleafall on 17-2-21.
//

#include <iostream>
#include <unordered_set>

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
	ListNode *EntryNodeOfLoop(ListNode *pHead) {
		if (!pHead) {
			return NULL;
		}
		ListNode *p = pHead, *slow = pHead, *fast = pHead;
		while (slow->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				while (slow != p) {
					slow = slow->next;
					p = p->next;
				}
				return p;
			}
		}
		return NULL;
	}
};

int main(){
	ListNode *node[5] = {0};
	for (int i = 0; i < 5; ++i) {
		node[i] = new ListNode(i);
		if (i) {
			node[i - 1]->next = node[i];
		}
	}
	node[4]->next = node[0];
//	node[0]->next = node[0];
	Solution solution;
	ListNode *p = NULL;
	ListNode *ans = solution.EntryNodeOfLoop(node[0]);
	if (ans) {
		cout << ans->val << endl;
	}
	for (int i = 0; i < 4; ++i) {
		delete node[i];
	}
}