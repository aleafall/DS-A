//
// Created by aleafall on 16-11-27.
//

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

bool isPrime(int n){
    if (n<=1) return 0;
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <=sqr; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
    map<int, int> mp;
    int n;
    cin >> n;
    cout << n << "=";
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <=sqr ; ++i) {
        if (isPrime(i) && n % i == 0) {
            mp[i] = 0;
            while (n % i == 0) {
                n /= i;
                mp[i]++;
            }
        }
        if (n == 1) {
            break;
        }
    }
    if (n != 1) {
        mp[n] = 1;
    }
    int len = (int) mp.size();
    for (auto item:mp) {
        if (item.second > 1) {
            cout << item.first << "^" << item.second;
        } else {
            cout << item.first;
        }
        --len;
        if (len) {
            cout << "*";
        } else {
            cout << endl;
        }
    }
    return 0;
}