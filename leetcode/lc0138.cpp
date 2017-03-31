//
// Created by aleafall on 16-11-7.
//

#include <iostream>
#include <map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        RandomListNode *newHead = new RandomListNode(head->label);
        RandomListNode *p = head, *q = newHead;
        map<int,RandomListNode*> i2p;
        map<RandomListNode*,int> p2i;
        int index=0;
        while (p) {
            p2i[p]=index++;
            p=p->next;
            if (p) {
                RandomListNode *node = new RandomListNode(p->label);
                q->next=node;
                q=node;
            }
        }
        p=head;
        q=newHead;
        while (p) {
            RandomListNode *r=newHead;
            if (p->random) {
                int rnd = p2i[p->random];
                while (rnd--) {
                    r=r->next;
                }
                q->random=r;
            }
            p=p->next;
            q=q->next;
        }
        return newHead;
    }
};
