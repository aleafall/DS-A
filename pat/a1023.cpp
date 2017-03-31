//
// Created by aleafall on 16-11-23.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isSame(string &s1,string &ans){
    string s2;
    int carry=0;
    for (int i = (int)s1.size() - 1; i >= 0; --i) {
        s2 += ((s1[i] - '0') * 2 + carry) % 10+'0';
        carry= ((s1[i] - '0') * 2 + carry) / 10;
    }
    if (carry) {
        s2 += carry + '0';
    }
    ans = s2;
    if (s1.size() != s2.size()) {
        return 0;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
int main(){
    string s,ans;
    cin >> s;
    if (isSame(s, ans)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    return 0;
}
