//
// Created by aleafall on 16-11-7.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int len=0;
        ListNode *now, *p = head, *q = head, *newHead = new ListNode(0);
        while (p) {
            ++len;
            p=p->next;
        }
        if (len == 0 || k == 0) {
            return head;
        }
        int times = len / k;
        p=head;
        now=newHead;
        for (size_t i = 0; i <times ; ++i) {
            for (size_t j = 0; j <k ; ++j) {
                ListNode *temp=p;
                p=p->next;
                temp->next=now->next;
                now->next=temp;
            }
            while (now->next) {
                now=now->next;
            }
        }
        if (len % k) {
            now->next=p;
        }
        return newHead->next;
    }
};

int main(){
    int n = 9,k=2;
    ListNode *node[n];
    for (size_t i = 0; i <n ; ++i) {
        node[i] = new ListNode((int) (i + 1));
        if (i) {
            node[i - 1]->next = node[i];
        }
    }
    Solution *solution=new Solution;
    ListNode *ans = solution->reverseKGroup(node[0], k);
    while (ans) {
        cout << ans->val << " ";
        ans=ans->next;
    }
    cout<<endl;
    for (size_t i = 0; i <n ; ++i) {
        delete node[i];
    }
    delete solution;
    return 0;
}