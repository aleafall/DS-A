//
// Created by aleafall on 16-12-3.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 100005;
const int High = INT32_MAX;
const int Low = INT32_MIN;

int main(){
    int n, a[maxn], vis[maxn] = {0};
    vector<int> ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int Min = Low, Max = High;
    for (int i = 0; i < n; ++i) {
        if (a[i] > Min) {
            vis[i]++;
        }
        Min = max(a[i], Min);
    }
    for (int i = n-1; i >=0 ; --i) {
        if (a[i] < Max) {
            vis[i]++;
            if (vis[i] == 2) {
                ans.push_back(a[i]);
            }
        }
        Max = min(Max, a[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    if (ans.empty()) {
        cout << endl;
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (i < ans.size() - 1) {
            printf("%d ", ans[i]);
        } else {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
