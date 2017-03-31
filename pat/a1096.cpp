//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int begin = n, ans = 0;
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        int m = n, j = i, cnt = 0;
        while (m % j == 0) {
            ++cnt;
            m /= j;
            ++j;
        }
        if (cnt > ans) {
            ans = cnt;
            begin = i;
        }
    }
    if (ans == 0) {
        cout << 1 << endl << n << endl;
        return 0;
    }
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        if (i < ans - 1) {
            cout << begin + i << "*";
        } else {
            cout << begin + i << endl;
        }
    }
    return 0;
}
