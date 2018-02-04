//
// Created by aleafall on 16-11-7.
//

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

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
	ListNode *oddEvenList(ListNode *head) {
		if (!head) {
			return nullptr;
		}
		ListNode *p = head, *q = NULL, *newHead = NULL, *pre = NULL;
		while (p) {
			pre = p;
			auto now = p->next;
			if (now) {
				p->next = now->next;
			}
			if (newHead) {
				q->next = now;
				q = now;
			} else {
				newHead = q = now;
			}
			p = p->next;
		}
		if (q) {
			q->next = NULL;
		}
		pre->next = newHead;
		return head;
	}
};

int main() {
	Solution *solution = new Solution;
	int n = 9;
	vector<int> vi{};
	ListNode *node[n];
	for (size_t i = 0; i < n; ++i) {
		node[i] = new ListNode((int) (i + 1));
		if (i) {
			node[i - 1]->next = node[i];
		}
	}
	ListNode *ans = solution->oddEvenList(node[0]);
	while (ans) {
		ListNode *temp = ans;
		cout << ans->val << " " << endl;
		ans = ans->next;
		delete temp;
	}
	delete solution;
	return 0;
}