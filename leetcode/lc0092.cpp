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
        ListNode *ans,*p=head,*post;
        ans = new ListNode(0);
        post=ans;
        int index = 1;
        for (; index < m; ++index) {
            ListNode *temp = p->next;
            p->next = post->next;
            post->next=p;
            post=p;
            p = temp;
        }
        for (; index <= n; ++index) {
            ListNode *temp = p->next;
            p->next = post->next;
            post->next = p;
            p = temp;
        }
        //        cout<<post->next->val<<endl;
        while (post && post->next) {
            cout<<post->val<<endl;
            post = post->next;
        }

        post->next=p;
        return ans->next;
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
