//
// Created by aleafall on 16-11-24.
//

#include <iostream>
#include <string>

using namespace std;

const int maxn = 1001;

bool flag[maxn] = {0};
struct User {
    string name, pwd;
} user[maxn];

char trans(char c) {
    switch (c) {
        case '1':
            return '@';
        case '0':
            return '%';
        case 'l':
            return 'L';
        case 'O':
            return 'o';
        default:
            break;
    }
    return c;
}

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> user[i].name >> user[i].pwd;
        for (int j = 0; j < user[i].pwd.size(); ++j) {
            char c = trans(user[i].pwd[j]);
            if (c != user[i].pwd[j]) {
                if (flag[i] == 0) {
                    flag[i] = 1;
                    ++cnt;
                }
                user[i].pwd[j] = c;
            }
        }
    }
    if (cnt) {
        cout << cnt << endl;
        for (int i = 0; i < n; ++i) {
            if (flag[i]) {
                cout << user[i].name << " " << user[i].pwd << endl;
            }
        }
    } else {
        if (n == 1) {
            cout << "There is 1 account and no account is modified\n";
        } else {
            printf("There are %d accounts and no account is modified\n", n);
        }
    }
    return 0;
}
