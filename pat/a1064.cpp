//
// Created by aleafall on 16-11-28.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1005;

int n,index=1;
int a[maxn], cbt[maxn];

void inOrder(int i){
    if (i>n) {
        return;
    }
    inOrder(2 * i);
    cbt[i] = a[index++];
    inOrder(2 * i + 1);
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <=n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    inOrder(1);
    for (int i = 1; i <=n ; ++i) {
        if (i < n) {
            printf("%d ", cbt[i]);
        } else {
            printf("%d\n", cbt[i]);
        }
    }
    return 0;
}
