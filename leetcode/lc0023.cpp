//
// Created by aleafall on 16-11-7.
//

#include <iostream>
#include <vector>
#include <algorithm>

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
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.empty()) {
			return NULL;
		}
		while (lists.size() > 1) {
			ListNode *l1 = lists.back();
			lists.pop_back();
			ListNode *l2 = lists.back();
			lists.pop_back();
			ListNode *newList = merge(l1, l2);
			lists.push_back(newList);
		}
		return lists.front();
	}

	ListNode *merge(ListNode *l1, ListNode *l2) {
		if (!l1) {
			return l2;
		}
		if (!l2) {
			return l1;
		}
		ListNode *head = NULL;
		if (l1->val < l2->val) {
			head = l1;
			l1 = l1->next;
		} else {
			head = l2;
			l2 = l2->next;
		}

		ListNode *p = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		p->next = l1 ? l1 : l2;
		return head;
	}
};

int main() {
	Solution solution;
	ListNode *node = new ListNode(1);
	vector<ListNode *> vi{node};
	auto head = solution.mergeKLists(vi);
	if (head) {
		cout << head->val << endl;
	} else {
		cout << "null\n";
	}
	return 0;
}