//
// Created by aleafall on 16-11-23.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<char> vc;
    for (int i = 0; i < 10; ++i) {
        vc.push_back((char &&) (i + '0'));
    }
    for (int i = 10; i < 13; ++i) {
        vc.push_back((char &&) ('A' + i - 10));
    }
    vector<int> ans(2,0);
    int color;
    cout << "#";
    for (int i = 0; i < 3; ++i) {
        cin >> color;
        ans[1] = color % 13;
        color /= 13;
        ans[0] = color;
        cout<<vc[ans[0]]<<vc[ans[1]];
        ans[0] = 0, ans[1] = 0;
    }
    cout<<endl;
    return 0;
}
