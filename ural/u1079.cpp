//
// Created by aleafall on 16-10-23.
//

#include <iostream>

using namespace std;

const int maxn=100005;
int a[maxn]={0};

int main(){
    int n=100000;
    for (int i = 0; i <= n; ++i) {
        if (i==0||i==1) a[i]=i;
        else{
            if (i & 1) {
                a[i] = a[i / 2] + a[i / 2 + 1];
            } else {
                a[i] = a[i / 2];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i]<a[i-1]) a[i] = a[i - 1];
    }
    while (cin >> n) {
        if (n==0) break;
        cout<<a[n]<<endl;
    }
    return 0;
}
