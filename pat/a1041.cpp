//
// Created by aleafall on 16-11-25.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100005;

int main(){
    int n, num[maxn], vis[maxn] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        vis[num[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (vis[num[i]] == 1) {
            cout << num[i] << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}
