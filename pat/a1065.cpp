//
// Created by aleafall on 16-11-28.
//

#include <iostream>

using namespace std;

int main() {
    int t;
    long long a, b, c;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        bool flag = 0;
        cin >> a >> b >> c;
        long long temp = a + b;
        if (a > 0 && b > 0 && temp <= 0) {
            flag = 1;
        } else if (a < 0 && b < 0 && temp >= 0) {

        } else if (temp > c) {
            flag = 1;
        }
        if (flag) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}

