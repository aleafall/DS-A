//
// Created by aleafall on 16-11-7.
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
    void reorderList(ListNode *head) {
        int num=0;
        ListNode* p=head,*q=head;
        while (p) {
            num++;
            p = p->next;
        }
//        cout<<"num "<<num<<endl;
        if (num <= 2) {
            return;
        }
        int half = (num + 1)/2;
        ListNode *pre=head;
        while (half--) {
            pre=q;
            q = q->next;
        }
        pre->next=NULL;
//        cout<<"q "<<q->val<<endl;
        ListNode *newHead = new ListNode(0);
        while (q) {
            ListNode *temp=q;
            q=q->next;
            temp->next=newHead->next;
            newHead->next=temp;
        }
        p=head,q=newHead->next;
        while (q) {
            ListNode* temp=q;
            q=q->next;
            temp->next=p->next;
            p->next=temp;
            p=p->next->next;
        }
        delete newHead;
//        p=head;
//        while (p!=NULL) {
//            cout<<"p "<<p->val<<endl;
//            p=p->next;
//        }
    }
};

int main(){
    int n=4;
    ListNode *node[n];
    for (int i = 0; i < n; ++i) {
        node[i] = new ListNode(i + 1);
        if (i) {
            node[i - 1]->next = node[i];
        }
    }
    Solution *solution=new Solution;
    solution->reorderList(node[0]);
    for (int i = 0; i < n; ++i) {
        cout << node[i]->val << " ";
        delete node[i];
    }
    cout<<endl;
    delete solution;
    return 0;
}