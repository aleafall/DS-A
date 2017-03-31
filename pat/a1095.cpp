//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 10005;

struct Rec {
    string id;
    int point;
    bool flag;
} rec[maxn];

bool cmp(Rec a,Rec b){
    if (a.id != b.id) {
        return a.id < b.id;
    }
    return a.point < b.point;
}
int main(){
    int n, k, hh, mm, ss;
    int Max = -1;
    int day = 24 * 3600 + 1;
    int a[day] = {0}, in[day] = {0}, out[day] = {0};
    vector<string> cars;
    char str[10], tag[5];
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%s %d:%d:%d %s", str, &hh, &mm, &ss, tag);
        rec[i].id = string(str);
        rec[i].point = hh * 3600 + mm * 60 + ss;
        rec[i].flag = tag[0] != 'i';
    }
    sort(rec, rec + n, cmp);
    int cnt = 0;
    for (int i = 0; i < n-1; ++i) {
        if (rec[i].id == rec[i + 1].id ) {
            if (!rec[i].flag && rec[i + 1].flag) {
                cnt += rec[i + 1].point - rec[i].point;
                in[rec[i].point]++;
                out[rec[i + 1].point]++;
            }
            if (i + 1 == n - 1) {
                if (cnt > Max) {
                    Max = cnt;
                    cars.clear();
                    cars.push_back(rec[i].id);
                } else if   (cnt==Max) {
                    cars.push_back(rec[i].id);
                }
            }
        } else {
            if (cnt > Max) {
                Max = cnt;
                cars.clear();
                cars.push_back(rec[i].id);
            } else if   (cnt==Max) {
                cars.push_back(rec[i].id);
            }
            cnt = 0;
        }
    }
    for (int i = 0; i < day; ++i) {
        if (i) {
            in[i] += in[i - 1];
            out[i] += out[i - 1];
        }
        a[i] += (in[i] - out[i]);
    }
    for (int i  = 0; i<k ; ++i) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        printf("%d\n", a[hh * 3600 + mm * 60 + ss]);
    }
    for (int i = 0; i < cars.size(); ++i) {
        printf("%s ", cars[i].c_str());
    }
    printf("%02d:%02d:%02d\n", Max / 3600, Max % 3600 / 60, Max % 60);
    return 0;
}
