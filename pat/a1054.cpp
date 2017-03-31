//
// Created by aleafall on 16-11-26.
//

#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, m, x;
    int ans = 0, flag = 0;
    cin >> n >> m;
    n *= m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (ans == x) {
            ++flag;
        } else {
            --flag;
            if (flag <= 0) {
                ans = x;
                flag = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
