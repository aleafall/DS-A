//
// Created by aleafall on 16-11-26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 100005;

int main(){
    int n, m, a[maxn], Min = 0x3fffffff;
    vector<int> vi;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int i = 0, j = 0;
    bool flag = 0;
    int temp = a[0];
    while (j < n) {
        while (temp < m && j < n) {
            temp += a[++j];
        }
        if (temp > m) {
            if (temp < Min) {
                Min = temp;
                vi.clear();
                vi.push_back(i);
            } else if (temp == Min) {
                vi.push_back(i);
            }
        } else if (temp == m) {
            printf("%d-%d\n", i + 1, j+1);
            flag = 1;
        }
        temp -= a[i++];
    }
    if (!flag) {
        for (i= 0; i < vi.size(); ++i) {
            temp = 0;
            for (j = vi[i]; j <n ; ++j) {
                temp += a[j];
                if (temp == Min) {
                    printf("%d-%d\n", vi[i] + 1, j + 1);
                    break;
                }
            }
        }
    }
    return 0;
}
