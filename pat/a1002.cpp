//
// Created by aleafall on 16-11-19.
//


#include <iostream>
#include <cstdio>

using namespace std;

const int maxn=1005;
int main(){
    double a[maxn] = {0};
    int k,e,cnt=0;
    double d;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> e >> d;
        a[e] += d;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> e >> d;
        a[e] += d;
    }
    for (int i = 0; i < maxn; ++i) {
        if (a[i] >= 0.05 || a[i] <= -0.05) {
            cnt++;
        }
    }
    if (cnt) {
        cout << cnt << " ";
    } else {
        cout<<cnt<<endl;
    }
    for (int i = maxn - 1; i >= 0; --i) {
        if (a[i] >= 0.05 || a[i] <= -0.05) {
            printf("%d %.1f", i, a[i]);
            cnt--;
            if (cnt) {
                cout << " ";
            } else {
                cout<<endl;
            }
        }
    }
    return 0;
}