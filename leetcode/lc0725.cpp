//
// Created by aleafall on 17-11-15.
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
	vector<ListNode *> splitListToParts(ListNode *root, int k) {
		vector<ListNode*> ans;
		int total = 0;
		ListNode *p = root;
		while (p) {
			total++;
			p = p->next;
		}
		p = root;
		int cnt = total / k, left = total % k;
		for (int i = 0; i < k; ++i) {
			int now = left-- >0? cnt + 1 : cnt;
			ans.push_back(p);
			for (int j = 0; p && j < now - 1; ++j) {
				p = p->next;
			}
			if (p) {
				auto temp = p->next;
				p->next = NULL;
				p = temp;
			}
		}
		return ans;
	}
};
