//
// Created by aleafall on 17-2-17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
		if (data.empty()) {
			return;
		}
		bool begin1 = 0, begin2 = 0;
		int ans1 = 0, ans2 = 0, temp = 0;
		for (int i = 0; i < data.size(); ++i) {
			i ? temp ^= data[i] : temp = data[i];
		}
		int flag = 1;
		while (!(temp & flag)) {
			flag <<= 1;
		}
		*num1 = *num2 = 0;
		for (auto &&item  :data) {
			if (item & flag) {
//				cout << "before " << *num1 << endl;
				begin1 ? ans1 ^= item : (begin1 = 1, ans1 = item);
//				cout << "after " << *num1 << endl;
			} else {
				begin2 ? ans2 ^= item : (begin2 = 1, ans2 = item);
			}
		}
//		cout << "ans1 ans2 " << ans1 << " " << ans2 << endl;
//		cout << "n1 n2 " << *num1 << " " << *num2 << endl;
		*num1 = ans1;
//		cout<<"num1 "<<*num1<<endl;
		*num2 = ans2;
//		cout<<"num2 "<<*num2<<endl;
	}
};

int main() {
	Solution solution;
	vector<int> vi{1, 1, 2, 3, 4, 4, 5, 5, 6, 6};
	int x = 0;
	int *a = &x, *b = &x;
	solution.FindNumsAppearOnce(vi, a, b);
	cout << *a << endl;
	cout << *b << endl;
}
