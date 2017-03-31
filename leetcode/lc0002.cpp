//
// Created by aleafall on 16-10-5.
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    ListNode() {

    }

    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        vector<int> v1, v2, v3;
        while (l1 != NULL) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        int i = 0, j = 0, k = 0;
        int carry = 0;
        while (i < v1.size() && j < v2.size()) {
            int now = (v1[i] + v2[j] + carry) % 10;
            carry = (v1[i] + v2[j] + carry) / 10;
            v3.push_back(now);
            i++;
            j++;
        }
        if (carry) {
            if (i < v1.size()) {
                while (i < v1.size()) {
                    int now = (v1[i] + carry) % 10;
                    carry = (v1[i] + carry) / 10;
                    v3.push_back(now);
                    i++;
                }
            } else if (j < v2.size()) {
                while (j < v2.size()) {
                    int now = (v2[j] + carry) % 10;
                    carry = (v2[j] + carry) / 10;
                    v3.push_back(now);
                    j++;
                }
            }
            if (carry) v3.push_back(carry);
        } else {
            while (i < v1.size()) v3.push_back(v1[i++]);
            while (j < v2.size()) v3.push_back(v2[j++]);
        }
        ListNode *p = new ListNode(v3[0]);
        ListNode *ans = p;
        for (int k = 1; k < v3.size(); ++k) {
            ListNode *temp = new ListNode(v3[k]);
            p->next = temp;
            p = temp;
        }
        return ans;
    }
};

int main() {

    return 0;
}