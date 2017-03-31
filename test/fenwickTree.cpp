//
// Created by aleafall on 17-3-18.
//

#include <iostream>

using namespace std;

const int maxn = 11;

int a[maxn] = {0,1,2,3,4,5,6,7,8,9,10};
int b[maxn] = {0};

int lowbit(int x){
	return x & (-x);
}
void build(){
	for (int i = 1; i <= 9; ++i) {
		int bit = lowbit(i);
		int cnt = 0;
//		cout << "bit " << bit << endl;
		for (int j = i; j > i - bit; --j) {
			b[i] += a[j];
			++cnt;
		}
		cout << "cnt " << cnt << endl;
	}
}

int main(){
	build();
	for (int i = 1; i <= 9; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= 9; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;
}
