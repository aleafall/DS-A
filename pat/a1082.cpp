//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <string>
#include<cstdlib>

using namespace std;

int main() {
    string s;
    cin >> s;
    string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string wei[5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

    int left = 0, right = s.size() - 1;
    if (s[0] == '-') {
        cout << "Fu";
        left++;
    }
    while (left + 4 <= right) {
        right -= 4;
    }
    while (left < s.size()) {
        bool flag = 0, isPrint = 0;
        while (left <= right) {
            if (left && s[left] == '0') {
                flag = 1;
            } else {
                if (flag) {
                    cout << " ling";
                    flag = 0;
                }
                if (left) {
                    cout << " ";
                }
                isPrint = 1;
                cout << num[s[left] - '0'];
                if (left != right) {
                    cout << " " << wei[right - left - 1];
                }
            }
            ++left;
        }
        if (isPrint && right != s.size() - 1) {
            cout << " " << wei[(s.size() - right - 1) / 4 + 2];
        }
        right += 4;
    }
    cout << endl;
    system("pause");
    return 0;
}