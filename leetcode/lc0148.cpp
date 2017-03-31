//
// Created by aleafall on 17-3-4.
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
	ListNode *sortList(ListNode *head) {
		if (!head) {
			return NULL;
		}
		ListNode *ans = 0;
		quickSort(ans,head, NULL);
		return ans;
	}

	void quickSort(ListNode *&ans, ListNode *begin, ListNode *end){
		if (!begin) {
			return;
		}
		ListNode *left = partition(begin);
		if (left) {
			if (!ans) {
				ans = left;
			} else if (ans->val > left->val) {
				ans = left;
			}
		}
		quickSort(ans,left, begin);
		quickSort(ans, begin->next, end);
	}
	ListNode *partition(ListNode *head){
		if (!head||!head->next) {
			return head;
		}
		ListNode *left = NULL, *p = head->next, *pre = head;
		while (p&&p!=) {
			if (p->val <= head->val) {
				pre->next = p->next;
				if (left) {
					p->next = left->next;
					left->next = p;
				} else {
					left = p;
				}
				p = pre->next;
			} else {
				pre = p;
				p = p->next;
			}
		}
		return left;
	}
};

