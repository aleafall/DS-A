//
// Created by aleafall on 17-3-1.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int main(){
	int n, a[maxn];
	int Min = INT32_MAX, Max = INT32_MIN, minAns = 0, maxAns = 0;
	vector<int> vi;
	auto it = vi.begin();

	while (cin>> n) {
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n && a[j] == a[i + 1]; ++j) {
				if (a[j] - a[i] < Min) {
					Min = a[j] - a[i];
					minAns = 1;
				} else if (a[j] - a[i] == Min) {
					minAns++;
				} else {
					break;
				}
			}
		}
		int left = 0, right = 0;
		int i=0;
		while (a[left] == a[0]) {
			++left;
		}
		while (a[n - 1 - right] == a[n - 1]) {
			++right;
		}
		a[0] == a[n - 1] ? minAns = maxAns = n * (n - 1) / 2 : maxAns = left * right;
		printf("%d %d\n", minAns, maxAns);
	}
	return 0;
}
