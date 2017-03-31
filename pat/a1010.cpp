//
// Created by aleafall on 16-11-20.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef long long LL;
const LL maxn = INT64_MAX;

LL trans(string &s, LL radix){
    LL ans=0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans = ans * radix + (s[i] - '0');
        } else {
            ans = ans * radix + (s[i] - 'a' + 10);
        }
        if (ans < 0) {
            return -1;
        }
    }
    return ans;
}

LL binarySearch(LL n1,string &s, LL left, LL right){
    while (left <= right) {
        LL mid;
        if ((left & 1) && (right & 1)) {
            mid = left / 2 + right / 2 + 1;
        } else {
            mid = left / 2 + right / 2;
        }
        LL now = trans(s, mid);
        if (now == n1) {
            return mid;
        } else if (now > n1||now==-1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
int main() {
    string s1,s2;
    LL tag,radix;
    cin >> s1 >> s2 >> tag >> radix;
    if (tag == 2) {
        swap(s1, s2);
    }
    LL left=0;
    for (int i = 0; i < s2.size(); ++i) {
        LL now;
        if (s2[i] >= '0' && s2[i] <= '9') {
            now = s2[i] - '0';
        } else {
            now = s2[i] - 'a' + 10;
        }
        left = max(left, now);
    }
    LL n1 = trans(s1, radix);
    LL high = max(n1, left) + 1;
    LL n2 = binarySearch(n1, s2, left + 1, high);
    if (n2 != -1) {
        cout<<n2<<endl;
    } else {
        cout<<"Impossible"<<endl;
    }
    return 0;
}

