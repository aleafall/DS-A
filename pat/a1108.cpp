//
// Created by aleafall on 16-12-3.
//

#include <iostream>

using namespace std;

bool check(string &s){
    int p = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '-') {
            if (i > 0 || s.size() == 1) {
                return 0;
            }
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9') {

        } else if (s[i] == '.') {
            ++p;
            if (p > 1) {
                return 0;
            }
            if (s.size() - i > 3) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}
int main(){
    double ans=0;
    int n, cnt = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        bool flag = 0;
        cin >> s;
        if (check(s)) {
//            cout << "test " <<s<< endl;
            double now;
            sscanf(s.c_str(), "%lf", &now);
            if (now >= -1000 && now <= 1000) {
                flag = 1;
//                cout << "now " << now << endl;
                ans += now;
                ++cnt;
            }
        }
        if (!flag) {
            printf("ERROR: %s is not a legal number\n", s.c_str());
        }
    }
    if (cnt) {
        if (cnt == 1) {
            printf("The average of 1 number is %.2f\n", ans);
        } else {
            printf("The average of %d numbers is %.2f\n", cnt, ans / cnt);
        }
    } else {
        printf("The average of 0 numbers is Undefined\n");
    }
    return 0;
}
