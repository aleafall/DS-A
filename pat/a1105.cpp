//
// Created by aleafall on 16-12-3.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N, m, n;
    cin >> N;
    int a[N + 1];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + N);
    m = (int) sqrt(1.0 * N);
    while (N%m) {
        ++m;
    }
    n = N / m;
    if (n > m) {
        swap(m, n);
    }
    int num[m + 1][n + 1];
    int index = N - 1;
    int minR = 0, maxR = m - 1, minC = 0, maxC = n - 1;
    while (index >= 0) {
        for (int nowC = minC,nowR=minR; nowC <=maxC ; ++nowC) {
            num[nowR][nowC] = a[index--];
        }
        ++minR;
        for (int nowR = minR,nowC=maxC; nowR <=maxR ; ++nowR) {
            num[nowR][nowC] = a[index--];
        }
        --maxC;
        if (index < 0) {
            break;
        }
        for (int nowC = maxC,nowR=maxR; nowC >=minC ; --nowC) {
            num[nowR][nowC] = a[index--];
        }
        --maxR;
        for (int nowR = maxR,nowC=minC; nowR >=minR ; --nowR) {
            num[nowR][nowC] = a[index--];
        }
        ++minC;
        if (index < 0) {
            break;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j < n - 1) {
                printf("%d ", num[i][j]);
            } else {
                printf("%d\n", num[i][j]);
            }
        }
    }
    return 0;
}
