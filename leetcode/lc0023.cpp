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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return NULL;
        vector<int> vi;
        for (size_t i = 0; i <lists.size() ; ++i) {
            vi.push_back((const int &) i);
        }
        while (vi.size() >= 2) {
            vector<int> temp;
            for (size_t i = 0; i <vi.size() ; i+=2) {
                if (i + 1 < vi.size()) {
                    ListNode *newHead = new ListNode(0);
                    ListNode *p = lists[vi[i]], *q = lists[vi[i + 1]],*r=newHead;
                    while (p && q) {
                        if (p->val < q->val) {
                            r->next=p;
                            r=r->next;
                            p=p->next;
                        } else {
                            r->next=q;
                            r=r->next;
                            q=q->next;
                        }

                    }
                    if (p) {
                        r->next=p;
                    }
                    if (q) {
                        r->next=q;
                    }
                    lists[vi[i]]=newHead->next;
                    delete newHead;
                    temp.push_back((const int &) vi[i]);
                } else {
                    temp.push_back((const int &) vi[i]);
                }

            }
            vi=temp;
        }
        return lists[0];
    }
};
