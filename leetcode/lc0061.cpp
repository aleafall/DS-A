//
// Created by aleafall on 16-10-20.
//

#include <iostream>
#include <algorithm>
#include <vector>

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
    ListNode *rotateRight(ListNode *head, int k) {
        int n=0;
        vector<ListNode*> vl;
        while(head!=NULL){
            vl.push_back(head);
            n++;
            head=head->next;
        }
        if (n==0) return NULL;
        k%=n;
        reverse(vl.begin(), vl.begin() + n - k);
        reverse(vl.begin() + n - k, vl.end());
        reverse(vl.begin(), vl.end());
        head=vl[0];
        for (size_t i = 0; i < vl.size(); ++i) {
            if (i==vl.size()-1) vl[i]->next=NULL;
            else vl[i]->next=vl[i+1];
        }
        return head;
    }
};
