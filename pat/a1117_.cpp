//
// Created by aleafall on 16-12-4.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;

int main(){
    int n, a[maxn];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int Max = -1;
    if (n == 1) {
        printf("1\n");
    } else {
        for (int i = n-2; i >=0 ; --i) {
            if (a[i] != a[i + 1] && a[i] <= n - i - 1) {
                Max = max(Max, a[i]);
            }
        }
        if (Max == -1) {
            Max = min(n, a[0]);
        }
        printf("%d\n", Max);
    }
    return 0;
}
