//
// Created by aleafall on 16-12-2.
//

#include <iostream>

using namespace std;

int main(){
    string s1, s2;
    int hashTable[256] = {0};
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] >= 'a' && s1[i] <= 'z') {
            s1[i] += 'A' - 'a';
        }
        hashTable[s1[i]]++;
    }
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] >= 'a' && s2[i] <= 'z') {
            s2[i] += 'A' - 'a';
        }
        hashTable[s2[i]]--;
    }
    for (int i = 0; i < s1.size(); ++i) {
        if (hashTable[s1[i]]) {
            cout << s1[i];
            hashTable[s1[i]] = 0;
        }
    }
    cout << endl;
    return 0;
}
