//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct F {
    int up, down;
} f;

void simp(int &v1,int &v2){
    int gcd = __gcd(abs(v1), abs(v2));
    v1 /= gcd;
    v2 /= gcd;
    if (v2 < 0) {
        v1 = -v1, v2 = -v2;
    }
}
void add(int v1,int v2){
    simp(v1, v2);
    int gcd = __gcd(v2, f.down);
    int gcm = v2 / gcd * f.down;
    f.up = gcm / f.down * f.up + gcm / v2 * v1;
    f.down = gcm;
    simp(f.up, f.down);

}
int main(){
    int n, v1, v2;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d/%d", &v1, &v2);
        if (i == 0) {
            f.up = v1;
            f.down = v2;
            simp(f.up,f.down);
        } else {
            add(v1, v2);
        }
    }
    if (f.up == 0) {
        printf("0\n");
    } else if (f.down == 1) {
        printf("%d\n", f.up);
    } else if (abs(f.up) > f.down) {
        printf("%d %d/%d\n", f.up / f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%d/%d\n", f.up, f.down);
    }
    return 0;
}