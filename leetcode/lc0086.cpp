//
// Created by aleafall on 16-11-7.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 *
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *p=head;
        vector<int > v1,v2;
        while (p) {
            if (p->val < x) {
                v1.push_back(p->val);
            } else {
                v2.push_back(p->val);
            }
            p = p->next;
        }
        p=head;
        for (size_t i = 0; i <v1.size() ; ++i) {
            p->val = v1[i];
            p=p->next;
        }
        for (size_t i = 0; i <v2.size() ; ++i) {
            p->val = v2[i];
            p=p->next;
        }
        return head;
    }
};
