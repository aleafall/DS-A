//
// Created by aleafall on 16-11-21.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPrime(int ans){
    if (ans<=1) return 0;
    for (int i = 2; i*i <=ans ; ++i) {
        if (ans % i == 0) {
            return 0;
        }
    }
    return 1;
}
bool check(int n,int radix){
    int m = n;
    int ans=0;
    while (n) {
        ans = ans * radix + n % radix;
        n /= radix;
    }
    return isPrime(m) && isPrime(ans);
}
int main(){
    int n,radix;
    while (cin >> n) {
        if (n < 0) {
            break;
        }
        cin >> radix;
        if (check(n, radix)) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
