//
// Created by aleafall on 16-11-27.
//

#include <cstdio>
#include <stack>

using namespace std;

const int maxn = 100005;
stack<int> st;
const int block = 317;
int a[block] = {0}, b[maxn] = {0};

void PeekMedian(){
    if (st.empty()) {
        printf("Invalid\n");
    } else {
        int mid = ((int) st.size() + 1) / 2;
        int index = 0, i = 0;
        while (index + a[i] < mid) {
            index += a[i++];
        }
        for (int j = block*i; index<mid ; ++j) {
            index += b[j];
            if (index >= mid) {
                printf("%d\n", j);
                return;
            }
        }
    }
}
int main(){
    char str[20];
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%s", str);
        if (str[1] == 'u') {
            scanf("%d", &x);
            st.push(x);
            a[x / block]++;
            b[x]++;
        } else if (str[1] == 'o') {
            if (st.empty()) {
                printf("Invalid\n");
            } else {
                x = st.top();
                st.pop();
                a[x / block]--;
                b[x]--;
                printf("%d\n", x);
            }
        } else {
            PeekMedian();
        }
    }
    return 0;
}


