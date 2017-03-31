//
// Created by aleafall on 16-11-24.
//
//if time limit exceed,just try more a few times.
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 505;

struct Sta {
    double dis, price;
} sta[maxn];

bool cmp(Sta a, Sta b) {
    return a.dis < b.dis;
}

int main() {
    double cmax, D, davg;
    int n;
    cin >> cmax >> D >> davg >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &sta[i].price, &sta[i].dis);
    }
    sta[n].dis = D, sta[n].price = 0;
    sort(sta, sta + n, cmp);
    double ans = 0, left = 0;
    int index = 0;
    if (sta[0].dis != 0) {
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }
    while (index < n) {
        int u = -1;
        double Min = 0x3fffffff;
        for (int i = index + 1; i <= n && sta[i].dis - sta[index].dis <= davg * cmax; ++i) {
            if (Min > sta[i].price) {
                u = i;
                Min = sta[i].price;
                if (Min < sta[index].price) {
                    break;
                }
            }
        }
        if (u == -1) {
            break;
        }
        if (sta[u].price < sta[index].price) {
            if (left * davg < sta[u].dis - sta[index].dis) {
                ans += (sta[u].dis - sta[index].dis - left * davg) / davg * sta[index].price;
                left = 0;
            } else {
                left -= (sta[u].dis - sta[index].dis) / davg;
            }
        } else {
            ans += (cmax - left) * sta[index].price;
            left = cmax - (sta[u].dis - sta[index].dis) / davg;
        }
        index = u;
    }
    if (index == n) {
        printf("%.2f\n", ans);
    } else {
        printf("The maximum travel distance = %.2f\n", sta[index].dis + cmax * davg);
    }
    return 0;
}
