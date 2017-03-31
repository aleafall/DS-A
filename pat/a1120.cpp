//
// Created by aleafall on 16-12-10.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, x;
    set<int> st;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        int temp = 0;
        while (x) {
            temp += x % 10;
            x /= 10;
        }
        st.insert(temp);
    }
    m = (int) st.size();
    cout << m << endl;
    for (auto item:st) {
        --m;
        if (m) {
            cout << item << " ";
        } else {
            cout << item << endl;
        }
    }
    return 0;
}
