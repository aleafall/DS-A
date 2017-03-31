//
// Created by aleafall on 16-12-6.
//

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

bool isPrime(int n){
    if (n < 2) {
        return 0;
    }
    int sqr = sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main(){
    int m, n,x;
    cin>>m>>n;
    while (!isPrime(m)) {
        ++m;
    }
    int a[m + 5];
    fill(a, a + m + 5, -1);
    bool vis[m + 5] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        for (int j = 0; j <=n ; ++j) {
            if (vis[(x + j * j) % m] == 0) {
                vis[(x + j * j) % m] = 1;
                a[i] = (x + j * j) % m;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            printf("%d", a[i]);
        } else {
            printf("-");
        }
        if (i < n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    return 0;

}
