//
// Created by aleafall on 17-5-9.
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
	long long Min;
	stack<long long > st;
public:
	/** initialize your data structure here. */
	MinStack() {
		Min = 0;
	}

	void push(int x) {
		if (st.empty()) {
			st.push((long long)x);
			Min = x;
		} else if (x >= Min) {
			st.push((long long int &&) x);
		} else {
			st.push( ((long long) x * 2 - Min));
			Min = x;
		}
	}

	void pop() {
		if (st.top() < Min) {
			Min =  ((long long) Min * 2 - st.top());
		}
		st.pop();
	}

	int top() {
		if (st.top() >= Min) {
			return st.top();
		} else {
			long long top = Min;
			Min =  ((long long) top * 2 - st.top());
			return top;
		}
	}

	int getMin() {
		return Min;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
