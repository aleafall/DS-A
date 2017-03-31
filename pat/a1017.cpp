//
// Created by aleafall on 16-11-22.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int maxn=10001;
const int maxk=101;
struct Cus {
    int arrive, dur;
} cus[maxn];

int convertTime(int hh, int mm, int ss){
    return hh * 3600 + mm * 60 + ss;
}

bool cmp(Cus a, Cus b){
    return a.arrive < b.arrive;
}
int main(){
    int n, k,cnt=0;
    cin >> n >> k;
    int hh, mm, ss;
    int endTime[maxk];
    int Begin = 8 * 3600, End = 17 * 3600;
    for (int i = 0; i < k; ++i) {
        endTime[i] = Begin;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &cus[i].dur);
        if (cus[i].dur > 60) {
            cus[i].dur = 3600;
        } else {
            cus[i].dur *= 60;
        }
        cus[i].arrive = convertTime(hh, mm, ss);
    }
    sort(cus, cus + n, cmp);
    int ans=0;
    for (int i = 0; i < n; ++i) {
        if (cus[i].arrive <= End) {
            ++cnt;
            int u = -1, Min = INT32_MAX;
            for (int j = 0; j <k ; ++j) {
                if (endTime[j] < Min) {
                    u = j;
                    Min = endTime[j];
                }
            }
            if (Min > cus[i].arrive) {
                ans += Min - cus[i].arrive;
            }
            if (endTime[u] > cus[i].arrive) {
                endTime[u] += cus[i].dur;
            } else {
                endTime[u] = cus[i].arrive + cus[i].dur;
            }
        }
    }
    if (cnt) {
        printf("%.1f\n", 1.0 * ans / cnt/60);
    } else {
        cout << "0.0\n";
    }
    return 0;
}