//
// Created by aleafall on 17-5-21.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	string fractionAddition(string expression) {
		string ans = "0/1";
		if (expression.empty()) {
			return "0/1";
		}
		string now;
		char ops = '+';
		bool flag = 0;
		for (int i = 0; i < expression.size(); ++i) {
			if (expression[i] != '+' && expression[i] != '-' ) {
				now += expression[i];
			} else {
				cout << "1 ans now " << ans << "  "<<now<<endl;
				ans = cal(ans, now, ops);
				cout << "2 ans now " << ans << "  "<<now<<endl;
				now = "";
				ops = expression[i];
			}
			if (i == (int) expression.size() - 1) {
				ans = cal(ans, now, ops);
			}
		}
		return ans;
	}

	string cal(string first, string second, char ops) {
		if (first.empty()) {
			first = "0/1";
		}
		if (second.empty()) {
			second = "0/1";
		}
		vector<int> t1 = split(first), t2 = split(second);
		pair<long long, long long> a(make_pair(t1.front(), t1.back()));
		pair<long long, long long> b(make_pair(t2.front(), t2.back()));
		Simplify(a);
		Simplify(b);
		pair<long long, long long> ans;
		ans.second = a.second * b.second;
		if (ops == '+') {
			ans.first = a.first * b.second + a.second * b.first;
		} else {
			ans.first = a.first * b.second - a.second * b.first;
		}
		Simplify(ans);
		auto ss = to_string(ans.first) + "/" + to_string(ans.second);
		return ss;
	}

	vector<int> split(string &str) {
		vector<int> ans;
		stringstream ss(str);
		string now;
		while (getline(ss, now, '/')) {
			ans.push_back(atoi(now.c_str()));
		}
		return ans;
	};

	void Simplify(pair<long long, long long> &p) {
		long long gcd = __gcd(abs(p.first), abs(p.second));
		p.first /= gcd, p.second /= gcd;
	}
};

int main() {
	Solution solution;
//	string str = "-1/2+1/2";
//	string str = "7/2+2/3-3/4";
	string str = "1/3-1/2";
	cout << solution.fractionAddition(str) << endl;
}