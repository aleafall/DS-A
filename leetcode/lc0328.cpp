//
// Created by aleafall on 16-11-7.
//

#include <iostream>
#include <vector>

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
    ListNode *oddEvenList(ListNode *head) {
        ListNode *p = head, *q;
        ListNode *newHead = new ListNode(0);
        q=newHead;
        if (head == NULL || head->next == NULL) {
            return head;
        }
        while (p&&p->next) {
            q->next = p->next;
            p->next=p->next->next;
            p=p->next;
            q=q->next;
        }
        if (q)
            q->next=NULL;
        p=head;
        while (p->next) {
            p=p->next;
        }
        p->next=newHead->next;
        delete newHead;
        return head;
    }
};

int main(){
    Solution *solution = new Solution;
    int n=9;
    vector<int> vi{};
    ListNode *node[n];
    for (size_t i = 0; i <n ; ++i) {
        node[i] = new ListNode((int) (i + 1));
        if (i) {
            node[i-1]->next=node[i];
        }
    }
    ListNode *ans = solution->oddEvenList(node[0]);
    while (ans) {
        ListNode *temp=ans;
        cout << ans->val << " " << endl;
        ans = ans->next;
        delete temp;
    }
    delete solution;
    return 0;
}