//
// Created by aleafall on 16-12-2.
//

#include <iostream>

using namespace std;

int main(){
    string s1, s2;
    int more = 0, less = 0;
    int vis[256] = {0};
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); ++i) {
        vis[s1[i]]++;
    }
    for (int i = 0; i < s2.size(); ++i) {
        vis[s2[i]]--;
    }
    for (int i = 0; i < 256; ++i) {
        if (vis[i] > 0) {
            more += vis[i];
        } else if (vis[i] < 0) {
            less -= vis[i];
        }
    }
    if (less == 0) {
        cout << "Yes " << more << endl;
    } else {
        cout << "No " << less << endl;
    }
    return 0;
}
