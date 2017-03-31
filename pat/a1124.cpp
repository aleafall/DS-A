//
// Created by aleafall on 17-3-6.
//

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int maxn = 1005;

int main(){
	int m, n, s;
	string names[maxn];
	unordered_set<string> ust;
	cin >> m >> n >> s;
	for (int i = 0; i < m; ++i) {
		cin >> names[i];
	}
	for (int i = 0; i < ceil(1.0 * m / n); ++i) {
		if (s > n) {
			cout << "Keep going...\n";
		} else {
			int cnt = 0;
			int index = i * n + (s - 1 + cnt) % n;
			while (ust.count(names[index]) && cnt < n) {
				++cnt;
				index = i * n + (s - 1 + cnt) % n;
			}
			if (cnt >= n) {
				cout << "Keep going...\n";
			} else {
				cout << names[index] << endl;
				ust.insert(names[index]);
			}
		}
	}
	return 0;
}
