//
// Created by aleafall on 16-12-3.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    string s, ans;
    string mar[25] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", "tam",
                      "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",};
    map<string, int> mp;
    for (int i = 0; i < 25; ++i) {
        mp[mar[i]] = i;
//        cout << mar[i] << " " << i << endl;
    }
//    cout << mp["tam"] << endl;
    cin >> n;
    getline(cin, s);
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        if (s[0] >= '0' && s[0] <= '9') {
            int num = atoi(s.c_str());
            if (num >= 13) {
                cout << mar[num / 13 + 12];
            }
            if (num / 13 && num % 13) {
                cout << " ";
            }
            if (num % 13) {
                cout << mar[num % 13];
            }
            cout << endl;
        } else {
            int ret;
            if (s.size() <= 4) {
                ret = mp[s];
            } else {
                string s1, s2;
                int j = 0;
                for (; j < s.size() && s[j] != ' '; ++j) {
                    s1 += s[j];
                }
                for (++j; j < s.size(); ++j) {
                    s2 += s[j];
                }
                ret = (mp[s1] - 12) * 13 + mp[s2];
            }
            cout << ret << endl;
        }
    }
    return 0;
}

