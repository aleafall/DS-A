//
// Created by aleafall on 16-10-23.
//
//todo
#include <iostream>

using namespace std;

const int maxn=1005;
int main(){
    int t, a[maxn] = {0}, b[maxn] = {0}, c[maxn] = {0};
    cin>>t;
    for (size_t j = 0; j <t ; ++j) {
        string str,s1,s2;
        bool flag1=0,flag2=0;
        while (str.empty()) {
            getline(cin, str);
        }
        int i=0;
        if (str[0] == '-') {
            str.erase(str.begin());
            flag1=1;
        }
        for (; i < str.size() && str[i] != ' '; ++i) {
            s1 += str[i];
        }
        ++i;
        if (str[i] == '-') {
            i++;
            flag2=1;
        }
        for (; i < str.size(); ++i) {
            s2 += str[i];
        }
        for (size_t k = s1.size()-1; k >=0 ; --k) {
            a[s1.size() - k - 1] = s1[k] - '0';
        }
        for (size_t k = s2.size()-1; k >=0 ; --k) {
            b[s2.size() - k - 1] = s2[k] - '0';
        }

    }
}
