//
// Created by aleafall on 16-11-20.
//

#include <iostream>

using namespace std;

const int maxn=1005;
int main(){
    double a[maxn]={0};
    double b[maxn] = {0};
    double c[2 * maxn] = {0};
    int k,e,cnt=0;
    double d;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> e >> d;
        a[e] = d;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> e >> d;
        b[e] = d;
        for (int j = 0; j < maxn; ++j) {
            c[e + j] += a[j] * b[e];
        }
    }
    for (int i = 0; i < 2 * maxn; ++i) {
        if (c[i] >= 0.05 || c[i] <= -0.05) {
            ++cnt;
        }
    }
    if (cnt) {
        cout << cnt << " ";
        for (int i = 2*maxn-1; i >=0 ; --i) {
            if (c[i] >= 0.05 || c[i] <= -0.05) {
                --cnt;
                printf("%d %.1f", i, c[i]);
                if (cnt) {
                    cout << " ";
                } else {
                    cout<<endl;
                }
            }
        }
    } else {
        cout<<cnt<<endl;
    }
    return 0;
}
