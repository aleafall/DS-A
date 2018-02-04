//
// Created by aleafall on 17-10-23.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
	priority_queue<int> q1;
	priority_queue<int, vector<int>, greater<int>> q2;
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (q1.empty()) {
			q1.push(num);
		} else if (q1.top() > num) {
			q1.push(num);
		} else {
			q2.push(num);
		}
		if (q1.size() > q2.size() + 1) {
			q2.push(q1.top());
			q1.pop();
		} else if (q2.size() > q1.size()) {
			q1.push(q2.top());
			q2.pop();
		}
	}

	double findMedian() {
		if (q1.size() == q2.size()) {
			return 0.5 * (q1.top() + q2.top());
		} else {
			return 1.0 * q1.top();
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main() {
    MedianFinder m;
	m.addNum(1);
	m.addNum(2);
	cout << m.findMedian() << endl;
	m.addNum(3);
	cout << m.findMedian() << endl;
    return 0;
}