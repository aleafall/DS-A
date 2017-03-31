//
// Created by aleafall on 17-3-3.
//

#include <iostream>

using namespace std;

int main(){
	string beg = "123456";
	string ans=beg;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		switch (str[i]) {
			case 'L':
				ans[0] = beg[4];
				ans[1] = beg[5];
				ans[4] = beg[1];
				ans[5] = beg[0];
				break;
			case 'R':
				ans[0] = beg[5];
				ans[1] = beg[4];
				ans[4] = beg[0];
				ans[5] = beg[1];
				break;
			case 'F':
				ans[2] = beg[4];
				ans[3] = beg[5];
				ans[4] = beg[3];
				ans[5] = beg[2];
				break;
			case 'B':
				ans[2] = beg[5];
				ans[3] = beg[4];
				ans[4] = beg[2];
				ans[5] = beg[3];
				break;
			case 'A':
				ans[0] = beg[3];
				ans[1] = beg[2];
				ans[2] = beg[0];
				ans[3] = beg[1];
				break;

			case 'C':
				ans[0] = beg[2];
				ans[1] = beg[3];
				ans[2] = beg[1];
				ans[3] = beg[0];
				break;

			default:
				break;
		}
		beg=ans;
	}
	cout << ans << endl;
}
