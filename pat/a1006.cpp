//
// Created by aleafall on 16-11-19.
//

#include <iostream>
#include <string>

using namespace std;

const int lower=24*3600+1;
const int upper=-1;

int main(){
    string unlock,lock,s;
    int n,in=lower, out=upper,h1,m1,s1,h2,m2,s2,t1,t2;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin>>s;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        t1 = h1 * 3600 + m1 * 60 + s1;
        t2 = h2 * 3600 + m2 * 60 + s2;
        if (t1 < in) {
            unlock = s;
            in = t1;
        }
        if (t2 > out) {
            lock = s;
            out = t2;
        }
    }
    cout << unlock << " " << lock << endl;
    return 0;
}
