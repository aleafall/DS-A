//
// Created by aleafall on 16-10-10.
//

#include <iostream>
#include <set>

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
    bool hasCycle(ListNode *head) {
        ListNode* p=head;
        set<ListNode*> st;
        while (p!=NULL){
            if (st.find(p)!=st.end()) return true;
            else st.insert(p);
            p=p->next;
        }
        return false;
    }
};
