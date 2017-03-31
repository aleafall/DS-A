//
// Created by aleafall on 16-11-23.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=100001;

int n, c;
struct Stu {
    int id, grade;
    string name;
} stu[maxn];

bool cmp(Stu a, Stu b){
    if (c == 1) {
        return a.id < b.id;
    } else if (c == 2) {
        if (a.name != b.name) {
            return a.name < b.name;
        } else {
            return a.id < b.id;
        }
    } else {
        if (a.grade != b.grade) {
            return a.grade < b.grade;
        } else {
            return a.id < b.id;
        }
    }
}
int main(){
    cin >> n >> c;
    char temp[10];
    for (int i = 0; i < n; ++i) {
        scanf("%d %s %d", &stu[i].id, temp, &stu[i].grade);
        int len = (int) strlen(temp);
        for (int j = 0; j < len; ++j) {
            stu[i].name += temp[j];
        }
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; ++i) {
        printf("%06d %s %d\n", stu[i].id, stu[i].name.c_str(), stu[i].grade);
    }
    return 0;
}
