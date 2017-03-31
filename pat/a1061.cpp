//
// Created by aleafall on 16-11-27.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    string day[7]{"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int i = 0;
    for (; i < min(s1.size(), s2.size()); ++i) {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s2[i] <= 'G') {
            cout << day[s1[i] - 'A'] << " ";
            break;
        }
    }
    for (++i; i < min(s1.size(), s2.size()); ++i) {
        if (s1[i] == s2[i]) {
            if (s1[i] >= '0' && s1[i] <= '9') {
                printf("%02d:", s1[i] - '0');
                break;
            } else if (s1[i] >= 'A' && s1[i] <= 'N') {
                printf("%02d:", s1[i] - 'A' + 10);
                break;
            }
        }
    }
    for (i = 0; i < min(s3.size(), s4.size()); ++i) {
        if (s3[i] == s4[i] && (s3[i] >= 'A' && s3[i] <= 'Z' || s3[i] >= 'a' && s3[i] <= 'z')) {
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}
