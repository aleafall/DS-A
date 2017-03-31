//
// Created by aleafall on 16-11-24.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    int n1,n2,n3,n;
    string s;
    cin >> s;
    n = (int) s.size();
    n1 = (n + 2) / 3;
    n2 = n + 2 - 2 * n1;
    for (int i = 0; i < n1; ++i) {
        if (i < n1 - 1) {
            cout << s[i];
            for (int j = 0; j < n2-2; ++j) {
                cout << " ";
            }
            cout << s[n - i - 1]<<endl;
        } else {
            for (int j = 0; j < n2; ++j) {
                cout << s[i + j];
            }
            cout<<endl;
        }
    }
    return 0;
}
