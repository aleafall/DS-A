//
// Created by aleafall on 16-12-2.
//

#include <iostream>

using namespace std;

const int mod = 1000000007;

int main(){
    string s;
    long long p = 0, pa = 0, pat = 0;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'P') {
            ++p;
        } else if (s[i] == 'A') {
            pa += p;
        } else {
            pat += pa;
        }
    }
    cout << pat % mod << endl;
    return 0;
}
