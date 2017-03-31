//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;

struct Stu {
    string name, id;
    int grade;
} stu[maxn];

bool cmp(Stu a, Stu b) {
    return a.grade > b.grade;
}

int main() {
    int n, cnt = 0;
    int grade1, grade2;
    char str1[15], str2[15];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%s %s %d", str1, str2, &stu[i].grade);
        stu[i].name = string(str1);
        stu[i].id = string(str2);
    }
    sort(stu, stu + n, cmp);
    cin >> grade1 >> grade2;
    for (int i = 0; i < n; ++i) {
        if (stu[i].grade >= grade1 && stu[i].grade <= grade2) {
            ++cnt;
            printf("%s %s\n", stu[i].name.c_str(), stu[i].id.c_str());
        }
    }
    if (!cnt) {
        printf("NONE\n");
    }
    return 0;
}