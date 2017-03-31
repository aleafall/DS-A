//
// Created by aleafall on 16-11-26.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
const int maxn = 1001;
int main(){
    int m, n, k, a[maxn];
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i) {
        stack<int> st;
        int index = 0;
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        for (int j = 1; j <=n; ++j) {
            st.push(j);
            if (st.size() > m) {
                break;
            }
            while (!st.empty() && st.top() == a[index]) {
                st.pop();
                ++index;
            }
        }
        if (st.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            while (!st.empty()) {
                st.pop();
            }
        }
    }
    return 0;
}
