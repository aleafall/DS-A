//
// Created by aleafall on 17-2-13.
//

#include <bits/stdc++.h>

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
	vector<int> printListFromTailToHead(ListNode *head) {
		vector<int> ans;
		while (head) {
			ans.push_back(head->val);
			head = head->next;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
