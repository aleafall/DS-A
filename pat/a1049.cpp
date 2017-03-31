//
// Created by aleafall on 16-11-26.
//


#include <iostream>

using namespace std;

int main(){
    int n, x = 1,left,right, ans = 0;
    cin >> n;
    while (n/x) {
        int now = n / x % 10;
        left = n / x / 10;
        right = n % x;
        if (now < 1) {
            ans += left * x;
        } else if (now > 1) {
            ans +=(left+1)*x;
        } else {
            ans += left * x + right + 1;
        }
        x *= 10;
    }
    cout << ans << endl;
}