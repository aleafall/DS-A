//
// Created by aleafall on 16-11-20.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    string s = "WTL";
    int index[3] = {0};
    double x,ans = 1,a[3]={0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> x;
            if (x >= a[i]) {
                index[i] = j;
                a[i] = x;
            }
        }
        ans *= a[i];
    }
    printf("%c %c %c %.2f\n", s[index[0]], s[index[1]], s[index[2]], (ans * 0.65 - 1) * 2);
    return 0;
}
