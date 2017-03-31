//
// Created by aleafall on 16-11-26.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1, s2;
    bool hashTable[256] = {0};
    getline(cin, s1);
    getline(cin, s2);
    for (auto c:s2) {
        hashTable[c] = 1;
    }
    for (auto c:s1) {
        if (!hashTable[c]) {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}
