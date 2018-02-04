//
// Created by aleafall on 16-10-6.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 *  */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
	    ListNode *newHead = new ListNode(0);
	    ListNode *pre = newHead;
	    pre->next = head;
	    n -= m;
	    while (--m) {
		    pre = pre->next;
	    }
	    ListNode *start = pre->next, *newStart = pre->next;
	    while (n--) {
		    auto now = start->next;
		    start->next = now->next;
		    now->next = newStart;
		    newStart = now;
		    pre->next = newStart;
	    }
	    return newHead->next;
    }
};

int main(){
    int n=2;
    ListNode *node[n];
    for (int i = 0; i < n; ++i) {
        node[i] = new ListNode(i);
        if (i) {
            node[i - 1]->next = node[i];
        }
    }
    node[0]->val=3;
    node[1]->val=5;
    Solution solution;
    ListNode *ans = solution.reverseBetween(node[0], 2, 2);
    for (int i = 0; i < n; ++i) {
        delete node[i];
    }
    return 0;
}
