//
// Created by aleafall on 16-10-10.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 *  */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
    ~ListNode(){
        cout<<"xiaohui"<<endl;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        if (head==NULL) return NULL;
        while (fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if (fast==NULL||slow==NULL) return NULL;
            if (fast==slow) {
                fast=head;
                while (fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};

int main(){
    ListNode* head=new ListNode(1);
//    head->next=head;
    Solution *solution=new Solution;
    if (solution->detectCycle(head)!=NULL) cout<<"yes\n";
    else cout<<"no\n";
    return 0;

}