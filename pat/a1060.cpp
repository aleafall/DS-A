//
// Created by aleafall on 16-11-27.
//

#include <iostream>
#include <string>

using namespace std;

int n;

string deal(string s, int &e) {
    int k=0;
    while (!s.empty() && s[0] == '0') {
        s.erase(s.begin());
    }
    if (s[0] == '.') {
        s.erase(s.begin());
        while (!s.empty() && s[0] == '0') {
            s.erase(s.begin());
            e--;
        }
    } else {
        while (k < s.size() && s[k] != '.') {
            ++k;
            ++e;
        }
        if (k < s.size()) {
            s.erase(s.begin() + k);
        }
    }
    if (s.empty()) {
        e = 0;
    }
    string ans;
    k = 0;
    while (k < n) {
        if (k < s.size()) {
            ans += s[k];
        } else {
            ans += '0';
        }
        ++k;
    }
    return ans;
}

int main(){

    string s1, s2;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    string ans1 = deal(s1, e1), ans2 = deal(s2, e2);
    if (ans1 == ans2) {
        cout << "YES 0." << ans1 << "*10^" << e1 << endl;
    } else {
        cout << "NO 0." << ans1 << "*10^" << e1 << " 0." << ans2 << "*10^" << e2 << endl;
    }
    return 0;
}
