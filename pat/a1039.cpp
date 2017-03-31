//
// Created by aleafall on 16-11-24.
//

#include<iostream>
#include<set>
#include<cstdio>

using namespace std;
const int maxn = 26 * 26 * 26 * 10;
set<int> st[maxn];

int trans(char s[]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (i < 3) sum = sum * 26 + s[i] - 'A';
        else sum = sum * 10 + s[i] - '0';
    }
    return sum;
}

int main() {
    int n, k, num, cnt;
    char name[5];
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> num >> cnt;
        for (int j = 0; j < cnt; j++) {
            getchar();
            scanf("%s", name);
            st[trans(name)].insert(num);
        }
    }
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%s", name);
        int id = trans(name);
        int len = (int) st[id].size();
        printf("%s %d", name, len);
        if (len) {
            putchar(' ');
            for (set<int>::iterator it = st[id].begin(); it != st[id].end(); it++) {
                if (len > 1) printf("%d ", *it);
                else printf("%d\n", *it);
                len--;
            }
        } else putchar('\n');
    }
    return 0;
}
