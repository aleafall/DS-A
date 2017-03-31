//
// Created by aleafall on 16-12-3.
//

#include <iostream>

using namespace std;

const int maxn = 100005;

int main(){
    int n;
    double a[maxn];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &a[i]);
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * (n - i) * (1 + i);
    }
    printf("%.2f\n", ans);
    return 0;
}
