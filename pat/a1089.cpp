//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, v;
    vector<int> pre, temp, part;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        pre.push_back(v);
    }
    temp = pre;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        part.push_back(v);
    }
    bool flag = 0;
    for (int i = 1; i <=n; ++i) {
        sort(temp.begin(), temp.begin() + i);
        if (temp == part) {
            flag = 1;
            while (temp == part) {
                ++i;
                sort(temp.begin(), temp.begin() + min(i, n));
            }
            cout << "Insertion Sort\n";
            for (int j = 0; j < temp.size(); ++j) {
                if (j < temp.size() - 1) {
                    cout << temp[j] << " ";
                } else {
                    cout << temp[j] << endl;
                }
            }
            break;
        }
    }
    if (!flag) {
        cout << "Merge Sort\n";
        for (int i = 2; i <= n; i *= 2) {
            for (int j = 0; j <n ; j+=i) {
                sort(pre.begin() + j, pre.begin() + min(j + i, n));
            }
            if (pre == part) {
                i *= 2;
                for (int j = 0; j <n ; j+=i) {
                    sort(pre.begin() + j, pre.begin() + min(j + i, n));
                }
                for (int j = 0; j < pre.size(); ++j) {
                    if (j < pre.size() - 1) {
                        cout << pre[j] << " ";
                    } else {
                        cout << pre[j] << endl;
                    }
                }
                break;
            }
        }
    }
    return 0;
}
