//
// Created by aleafall on 16-10-25.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        int n=0;
        ListNode *p=head,*q;
        while (p != NULL) {
            ++n;
            p=p->next;
        }
        if (n<=1) {
            return 1;
        }
        p=head;
        int cnt=0;
        for (int i = 0; i < (n+1)/2; ++i) {
            p=p->next;
        }
        q=p;
        ListNode *newHead=new ListNode(0);
        while (q != NULL) {
            ListNode *temp=q;
            q=q->next;
            temp->next=newHead->next;
            newHead->next=temp;
        }
        newHead=newHead->next;
        while (head && newHead) {
            if (head->val != newHead->val) {
                return 0;
            }
            head=head->next;
            newHead=newHead->next;
        }
        return 1;
    }
};
