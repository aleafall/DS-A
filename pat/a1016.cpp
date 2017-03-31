//
// Created by aleafall on 16-11-22.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int maxn=1001;

int toll[24];
struct Cus {
    string name, flag;
    int m, dd, hh, mm;
} cus[maxn];

int convertTime(int dd, int hh, int mm){
    return dd * 24 * 60 + hh * 60 + mm;
}
bool cmp(Cus a, Cus b){
    if (a.name != b.name) {
        return a.name < b.name;
    } else {
        return convertTime(a.dd, a.hh, a.mm) < convertTime(b.dd, b.hh, b.mm);
    }
}

int cal(int dd1, int hh1, int mm1, int dd2, int hh2, int mm2){
    int ans=0;
    while (dd1 < dd2 || hh1 < hh2 || mm1 < mm2) {
        ++mm1;
        ans += toll[hh1];
        if (mm1 == 60) {
            mm1 = 0;
            ++hh1;
        }
        if (hh1 == 24) {
            hh1 = 0;
            ++dd1;
        }
    }
    return ans;
}
int main(){
    int n;
    for (int i = 0; i < 24; ++i) {
        cin >> toll[i];
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cus[i].name;
        scanf("%d:%d:%d:%d", &cus[i].m, &cus[i].dd, &cus[i].hh, &cus[i].mm);
        cin >> cus[i].flag;
    }
    sort(cus, cus + n, cmp);
    int time=0;
    int total=0;
    string cur = cus[0].name;
    for (int i = 0; i < n-1; ++i) {
        if (cus[i].name == cur && cus[i].name == cus[i + 1].name) {
            if (cus[i].flag == "on-line" && cus[i + 1].flag == "off-line") {
                int nowTime = 0, nowMoney = 0;
                nowTime = convertTime(cus[i + 1].dd, cus[i + 1].hh, cus[i + 1].mm) -
                        convertTime(cus[i].dd, cus[i].hh, cus[i].mm);
                nowMoney = cal(cus[i].dd, cus[i].hh, cus[i].mm, cus[i + 1].dd, cus[i + 1].hh, cus[i + 1].mm);
                if (time == 0) {
                    printf("%s %02d\n", cur.c_str(), cus[i].m);
                }
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", cus[i].dd, cus[i].hh, cus[i].mm,
                       cus[i + 1].dd, cus[i + 1].hh, cus[i + 1].mm, nowTime, .01 * nowMoney);
                time += nowTime;
                total += nowMoney;

            }
//            if (i + 1 == n - 1) {
//                printf("Total amount: $%.2f\n", .01 * total);
//            }
        } else {
            if (total)
                printf("Total amount: $%.2f\n", .01 * total);
            cur = cus[i + 1].name;
            time=0;
            total=0;
        }
    }
    if (total) {
        printf("Total amount: $%.2f\n", .01 * total);
    }
    return 0;
}
