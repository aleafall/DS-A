//
// Created by aleafall on 17-2-21.
//

#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;

	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode *GetNext(TreeLinkNode *pNode) {
		if (!pNode) {
			return NULL;
		}
		TreeLinkNode *ans = NULL;
		if (pNode->right) {
			ans = pNode->right;
			while (ans->left) {
				ans = ans->left;
			}
			return ans;
		} else {
			TreeLinkNode *father = pNode->next;
			if (father && father->left == pNode) {
				return father;
			} else {
				while (father) {
					TreeLinkNode *grandfather = father->next;
					if (grandfather && grandfather->left == father) {
						return grandfather;
					}
					father = grandfather;
				}
				return NULL;
			}
		}
	}
};
