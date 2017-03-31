//
// Created by aleafall on 17-2-21.
//

#include <iostream>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;

	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode *Clone(RandomListNode *pHead) {
		if (!pHead) {
			return NULL;
		}
		RandomListNode *p = pHead;
		while (p) {
			RandomListNode *newNode = new RandomListNode(p->label);
			newNode->next = p->next;
			p->next = newNode;
			p = p->next->next;
		}
		RandomListNode *newHead = pHead->next;
		p = pHead;
		while (p) {
			if (p->random) {
				p->next->random = p->random->next;
			}
			p = p->next->next;
		}
		p = pHead;
		while (p) {
			RandomListNode *newNode = p->next;
			RandomListNode *next = p->next->next;
			if (next) {
				newNode->next = next->next;
			} else {
				newNode->next = NULL;
			}
			p->next = next;
			p = next;
		}
		return newHead;
	}
};

int main(){
	RandomListNode *node[3];
	node[0] = new RandomListNode(0);
	node[1] = new RandomListNode(1);
	node[2] = new RandomListNode(2);
	node[0]->next = node[1], node[0]->random = node[2];
	node[1]->next = node[2], node[1]->random = node[0];
	node[2]->random = node[1];
	RandomListNode *pHead = new RandomListNode(-1);
	RandomListNode *pH = NULL;
	pHead->random = pHead;
	Solution solution;
	RandomListNode *ans = solution.Clone(pH);
	for (int i = 0; i < 3; ++i) {
		delete node[i];
	}
	RandomListNode *p = ans;
	while (p) {
		cout << p->label << " " << p->random->label << endl;
		p = p->next;
	}
	p = ans;
	while (p) {
		RandomListNode *q = p;
		p = p->next;
		delete q;
	}
}