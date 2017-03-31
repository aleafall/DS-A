//
// Created by aleafall on 16-11-24.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 10001;
bool cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    string str[maxn], ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    for (int i = 0; i < n; ++i) {
        ans += str[i];
    }
    while (!ans.empty() && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    if (ans.empty()) {
        ans = "0";
    }
    cout << ans << endl;
    return 0;
}

