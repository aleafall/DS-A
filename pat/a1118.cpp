//
// Created by aleafall on 16-9-28.
//

#include <iostream>
#include <set>

using namespace std;

const int maxn = 10005;

int father[maxn];

int findFather(int x) {

    if (father[x] == x) return x;
    else {
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}

int main() {
    for (int i = 0; i < maxn; ++i) {
        father[i] = i;
    }
    int n, k, index, b = 0;
    int q, b1, b2;
    set<int> st;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        int temp = 0;
        for (int j = 0; j < k; ++j) {
            cin >> index;
            if (index > b) b = index;
            if (j == 0) temp = index;
            else Union(temp, index);
        }
    }
    for (int i = 1; i <= b; ++i) {
        st.insert(findFather(i));
    }
    cout << st.size() << " " << b << endl;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> b1 >> b2;
        if (father[b1] == father[b2])
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
