//
// Created by t-xiuyan on 7/15/2017.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseList(ListNode *head) {
		if (!head) {
			return nullptr;
		}
		ListNode *newHead = head, *cur = NULL;
		while (head->next) {
			cur = head->next;
			head->next = cur->next;
			cur->next = newHead;
			newHead = cur;
		}
		return newHead;
	}
};
