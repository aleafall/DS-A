//
// Created by aleafall on 16-11-22.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> trans(int n, int base) {
    vector<int> vi;
    if (n == 0) {
        vi.push_back(0);
        return vi;
    }
    while (n) {
        vi.push_back(n % base);
        n /= base;
    }
    return vi;
}
int main(){
    int n,base;
    vector<int> v1, v2;
    cin >> n >> base;
    v1 = trans(n, base);
    v2=v1;
    reverse(v1.begin(), v1.end());
    if (v1 == v2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (i < v1.size() - 1) {
            cout << v1[i] << " ";
        } else {
            cout << v1[i] << endl;
        }
    }
    return 0;
}
