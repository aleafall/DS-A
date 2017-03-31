//
// Created by aleafall on 16-11-7.
//

#include <iostream>
#include <vector>
#include <algorithm>


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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        vector<int> v1,v2;
        ListNode *p=l1,*q=l2;
        while (p) {
            v1.push_back(p->val);
            p = p->next;
        }
        while (q) {
            v2.push_back(q->val);
            q = q->next;
        }
        vector<int> ans;
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        int carry=0;
        for (size_t i = 0; i < max(v1.size(), v2.size()); ++i) {
            int now=0;
            if (i < v1.size() && i < v2.size()) {
                now = (v1[i] + v2[i] + carry) % 10;
//                cout<<"now "<<now<<endl;
                carry=(v1[i]+v2[i]+carry)/10;
            } else if (i < v1.size()) {
                now = (v1[i]  + carry) % 10;
                carry=(v1[i]+carry)/10;
            } else {
                now = (v2[i]  + carry) % 10;
                carry=(v2[i]+carry)/10;
            }
            ans.push_back(now);
//            cout<<"carry "<<carry<<endl;
        }
        if (carry) {
            ans.push_back(carry);
        }
        if (ans.empty()) {
            ans.push_back(0);
        }
        ListNode *head = new ListNode(ans[ans.size()-1]);
        p=head;
        for (int i = (int) ans.size() - 2; i >= 0; --i) {
            ListNode *node = new ListNode(ans[i]);
            p->next=node;
            p=p->next;
        }
        return head;
    }
};

int main(){
    Solution *solution=new Solution;
    int n=3;
    ListNode *l1[n], *l2[n];
    vector<int> v1{2, 4, 3}, v2{5, 6, 4};
    for (size_t i = 0; i < n; ++i) {
        l1[i] = new ListNode(v1[i]);
        l2[i] = new ListNode(v2[i]);
        if (i) {
            l1[i - 1]->next = l1[i];
            l2[i - 1]->next = l2[i];
        }
    }
    ListNode *ans = solution->addTwoNumbers(l1[0], l2[0]);
    ListNode *pre;
    while (ans) {
        cout << ans->val << " ";
        pre=ans;
        ans = ans->next;
        delete pre;
    }
    for (int i = 0; i < n; ++i) {
        delete l1[i];
        delete l2[i];
    }
    return 0;
}