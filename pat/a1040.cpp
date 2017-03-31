//
// Created by aleafall on 16-11-25.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    if (s.size() == 1 || s.size() == 2) {
        cout << s.size() << endl;
    } else {
        int ans = 0;
        for (int i = 1; i < s.size() - 1; ++i) {
            int j = i - 1, k = i + 1;
            while (j >= 0 && k < s.size()) {
                if (s[j] != s[k]) {
                    break;
                } else {
                    --j;
                    ++k;
                }
            }
            ans = max(ans, k - j - 1);
            j = i, k = i + 1;
            while (j >= 0 && k < s.size()) {
                if (s[j] != s[k]) {
                    break;
                } else {
                    --j;
                    ++k;
                }
            }
            ans = max(ans, k - j - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
