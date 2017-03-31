//
// Created by aleafall on 16-10-23.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int n;
    while (cin >> n) {
        if (n==0) break;
        map<string,int> mp;
        string s;
        int Max=-1;
        for (size_t i = 0; i <n ; ++i) {
            cin>>s;
            if (mp.find(s) != mp.end()) {
                mp[s]++;
            } else {
                mp[s]=1;
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second > Max) {
                Max=it->second;
                s=it->first;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
