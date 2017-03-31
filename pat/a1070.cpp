//
// Created by aleafall on 16-11-29.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1001;

struct Mc {
    double amount, price, unit;
} mc[maxn];

bool cmp(Mc a,Mc b){
    return a.unit > b.unit;
}
int main(){
    int n;
    double ton;
    cin >> n >> ton;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &mc[i].amount);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &mc[i].price);
        mc[i].unit = mc[i].price / mc[i].amount;
    }
    sort(mc, mc + n, cmp);
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        if (ton <= mc[i].amount) {
            ans += mc[i].unit * ton;
            break;
        } else {
            ans += mc[i].price;
            ton -= mc[i].amount;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
