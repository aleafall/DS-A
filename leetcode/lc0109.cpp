//
// Created by aleafall on 17-1-29.
//

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (!head) {
			return NULL;
		}
		int size = 0;
		ListNode *p = head;
		while (p) {
			size++;
			p = p->next;
		}
		ListNode *pre = NULL;
		p = head;
		for (int i = 0; i < size / 2; ++i) {
			pre = p;
			p = p->next;
		}
		TreeNode *root = new TreeNode(p->val);
		if (pre) {
			pre->next = NULL;
			root->left = sortedListToBST(head);
		}
		root->right = sortedListToBST(p->next);
		return root;
	}
};

