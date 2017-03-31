//
// Created by aleafall on 16-12-4.
//

#include <iostream>

using namespace std;

int main() {
    int k;
    bool check[256] = {0};
    bool vis[256] = {0};
    string s, tag;
    cin >> k >> s;
    int i=0;
    while (i < s.size()) {
        int j = i;
        while (j < s.size() && s[j] == s[i]) {
            ++j;
        }
        if ((j-i)%k==0) {
            if (check[s[i]] == 0&&vis[s[i]]==0) {
                tag+=s[i];
                check[s[i]] = 1;
            }
        } else {
            check[s[i]] = 0;
        }
        vis[s[i]] = 1;
        i = j;
    }
    for (int m = 0; m < tag.size(); ++m) {
        if (check[tag[m]]) {
            cout << tag[m];
        }
    }
    cout << endl;
    i = 0;
    while (i < s.size()) {
        int j = i;
        while (j < s.size() && s[j] == s[i]) {
            ++j;
        }
        if (check[s[i]]) {
            for (int l = 0; l <(j-i)/k ; ++l) {
                cout<<s[i];
            }
        } else {
            for (int l = 0; l < (j-i); ++l) {
                cout << s[i];
            }
        }
        i = j;
    }
    cout << endl;
    return 0;
}
