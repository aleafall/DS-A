//
// Created by aleafall on 17-2-26.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	stack<int> norStack,minStack;
	void push(int value) {
		norStack.push(value);
		if (minStack.empty() || minStack.top() > value) {
			minStack.push(value);
		}
	}
	void pop() {
		if (minStack.top() == norStack.top()) {
			minStack.pop();
		}
		norStack.pop();
	}
	int top() {
		return norStack.top();
	}
	int min() {
		return minStack.top();
	}
};
