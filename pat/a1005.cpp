//
// Created by aleafall on 16-11-19.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string mp[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string N,ans;
    int sum=0;
    cin>>N;
    for (char c:N) {
        sum += c - '0';
    }
    ans = to_string(sum);
    for (int i = 0; i < ans.size(); ++i) {
        if (i < ans.size() - 1) {
            cout << mp[ans[i] - '0'] << " ";
        } else {
            cout<<mp[ans[i]-'0']<<endl;
        }
    }
    return 0;
}
