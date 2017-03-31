//
// Created by aleafall on 17-3-3.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string s;
	cin >> s;
	reverse(s.begin(), s.end());
	string ans;
	int carry = 0;
	for (int i = 0; i < s.size(); ++i) {
		int now;
		if (i == 0) {
			now = (s[i] - '0' + 1+carry) % 10;
			carry = (s[i] - '0' + 1 + carry) / 10;
		} else {
			now = (s[i] - '0' +carry) % 10;
			carry = (s[i] - '0' + 1 + carry) / 10;
		}
		ans += to_string(now);
	}
	if (carry) {
		ans += to_string(carry);
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
