//
// Created by aleafall on 16-11-20.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn=10005;

int main(){
    int a[maxn], b[maxn];
    int k,ans=-1,begin,end;
    cin >> k;
    for (int i = 0; i <k ; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < k; ++i) {
        if (i) {
            b[i] = max(b[i - 1] + a[i], a[i]);
        } else {
            b[i] = a[i];
        }
        if (b[i] > ans) {
            end = i;
            ans = b[i];
        }
    }
    if (ans >= 0) {
        cout << ans << " ";
        begin=end;
        while (ans-a[begin] != 0) {
            ans -= a[begin];
            begin--;
        }
        cout<<a[begin]<<" "<<a[end]<<endl;
    } else {
        cout<<0<<" "<<a[0]<<" "<<a[k-1]<<endl;
    }
    return 0;
}
