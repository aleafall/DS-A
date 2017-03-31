//
// Created by aleafall on 16-11-19.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    a += b;
    if (a < 0) {
        cout << "-";
        a=-a;
    }
    if (a >= 1000000) {
        printf("%d,%03d,%03d", a / 1000000, a % 1000000 / 1000, a % 1000);
    } else if (a >= 1000) {
        printf("%d,%03d", a / 1000, a % 1000);
    } else {
        cout<<a;
    }
    cout<<endl;
    return 0;
}
