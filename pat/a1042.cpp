//
// Created by aleafall on 16-11-25.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 54;

int main(){
    int k;
    string letter("SHCDJ");
    vector<string> vs(N), temp(N);
    for (int i = 0; i < N; ++i) {
        if (i < 13) {
            vs[i] = letter[0] + to_string(i+1);
        } else if (i < 26) {
            vs[i] = letter[1] + to_string(i - 13 + 1);
        } else if (i < 39) {
            vs[i] = letter[2] + to_string(i-26+1);
        } else if (i<52){
            vs[i] = letter[3] + to_string(i - 39 + 1);
        } else {
            vs[i] = letter[4] + to_string(i - 52 + 1);
        }
    }
    vector<int> order(N);
    cin >> k;
    for (int i = 0; i < N; ++i) {
        cin >> order[i];
    }
    while (k--) {
        for (int i = 0; i < N; ++i) {
            temp[order[i] - 1] = vs[i];
        }
        vs = temp;
    }
    for (int i = 0; i < N; ++i) {
        if (i < N - 1) {
            cout << vs[i] << " ";
        } else {
            cout << vs[i] << endl;
        }
    }
    return 0;
}
