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
		if (!head || !head->next) {
			return head;
		}
//		quickSort(head, NULL);
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *mid = slow->next;
		slow->next = NULL;
		ListNode *p1 = sortList(head);
		ListNode *p2 = sortList(mid);
		return merge(p1, p2);
	}

	ListNode *mergeSort(ListNode *head, int len) {
		if (len <= 1) {
			head->next = NULL;
			return head;
		}
		ListNode *mid = head;
		for (int i = 0; i < len / 2; ++i) {
			mid = mid->next;
		}
		cout << "test\n";
		ListNode *p1 = mergeSort(head, len / 2);
		ListNode *p2 = mergeSort(mid, len - len / 2);
		return merge(p1, p2);
	}

	ListNode *merge(ListNode *p1, ListNode *p2) {
		if (!p1) {
			return p2;
		}
		if (!p2) {
			return p1;
		}
		ListNode *p = NULL, *head = NULL;
		if (p1->val < p2->val) {
			head = p1;
			p1 = p1->next;
		} else {
			head = p2;
			p2 = p2->next;
		}
		p = head;
		while (p1 && p2) {
			if (p1->val < p2->val) {
				p->next = p1;
				p1 = p1->next;
			} else {
				p->next = p2;
				p2 = p2->next;
			}
			p = p->next;
		}
		p->next = p1 ? p1 : p2;
		return head;
	}

	void quickSort(ListNode *left, ListNode *right) {
		if (left != right) {
			ListNode *mid = partition(left, right);
			quickSort(left, mid);
			quickSort(mid->next, right);
		}
	}

	ListNode *partition(ListNode *left, ListNode *right) {
		int key = left->val;
		ListNode *p = left, *q = left->next;
		while (q != right) {
			if (q->val < key) {
				p = p->next;
				swap(p->val, q->val);
			}
			q = q->next;
		}
		swap(p->val, left->val);
		return p;
	}
};

int main() {
	Solution solution;
	ListNode *node[10];
	for (int i = 0; i < 10; ++i) {
		node[i] = new ListNode(rand()%100);
		cout << node[i]->val << " ";
		if (i) {
			node[i - 1]->next = node[i];
		}
	}
	cout << endl;
	solution.sortList(node[0]);
	for (int i = 0; i < 10; ++i) {
		cout << node[i]->val << " ";
		delete node[i];
	}
	cout << endl;
}
