//
// Created by aleafall on 17-5-26.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MyStack {
	queue<int> q1,q2;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		if (q1.empty()) {
			q2.push(x);
		} else {
			q1.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (q1.empty()) {
			while (q2.size() > 1) {
				q1.push((int &&) q2.front());
				q2.pop();
			}
			int ans = q2.front();
			q2.pop();
			return ans;
		} else {
			while (q1.size() > 1) {
				q2.push((int &&) q1.front());
				q1.pop();
			}
			int ans = q1.front();
			q1.pop();
			return ans;
		}
	}

	/** Get the top element. */
	int top() {
		int ans = 0;
		if (q1.empty()) {
			while (!q2.empty()) {
				if (q2.size() == 1) {
					ans = q2.front();
				}
				q1.push((int &&) q2.front());
				q2.pop();
			}
		} else {
			while (!q1.empty()) {
				if (q1.size() == 1) {
					ans = q1.front();
				}
				q2.push((int &&) q1.front());
				q1.pop();
			}
		}
		return ans;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
