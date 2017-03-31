//
// Created by aleafall on 16-11-29.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;

int main() {
    int n, a[maxn], pos[maxn];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    int ans = 0, k = 0;
    while (k < n) {
        if (a[0] == 0) {
            for (; k < n; ++k) {
                if (a[k] != k) {
                    pos[0] = k;
                    pos[a[k]] = 0;
                    swap(a[0], a[k]);
                    ++ans;
                    break;
                }
            }
        }
        if (a[0]) {
            swap(a[pos[0]], a[pos[pos[0]]]);
            swap(pos[0], pos[pos[0]]);
            ++ans;
        }
    }
    /*while (pos[0] || k == 0) {
        if (pos[0]) {
            swap(a[pos[0]], a[pos[pos[0]]]);
            swap(pos[0], pos[pos[0]]);
            ++ans;
        }
        if (pos[0] == 0) {
            for (; k < n; ++k) {
                if (a[k] != k) {
                    pos[0] = k;
                    pos[a[k]] = 0;
                    swap(a[k], a[0]);
                    ++ans;
                    break;
                }
            }
        }
    }*/
    cout << ans << endl;
    return 0;
}
