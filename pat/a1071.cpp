//
// Created by aleafall on 16-11-29.
//

#include <iostream>
#include <map>
#include <sstream>

using namespace std;

bool check(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int main() {
    string s;
    map<string, int> mp;
    getline(cin, s);
    int i = 0;
    while (i < s.size()) {
        string word;
        for (; i < s.size() && check(s[i]); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                word += s[i] - 'A' + 'a';
            } else {
                word += s[i];
            }
        }
        if (!word.empty()) {
            if (mp.find(word) != mp.end()) {
                mp[word]++;
            } else {
                mp[word] = 1;
            }
        }
        while (!check(s[i]) && i < s.size()) {
            ++i;
        }
    }
    string ans;
    int Max = -1;
    for (auto item:mp) {
        if (item.second > Max) {
            Max = item.second;
            ans = item.first;
        }
    }
    cout << ans << ' ' << Max << endl;
    return 0;
}
