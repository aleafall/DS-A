//
// Created by aleafall on 16-11-26.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 100005;

struct Rich {
    string name;
    int age, wealth;
} rich[maxn];

bool cmp(Rich a, Rich b){
    if (a.wealth != b.wealth) {
        return a.wealth > b.wealth;
    } else if (a.age != b.age) {
        return a.age < b.age;
    } else {
        return a.name < b.name;
    }
}

int main(){
    int n, k, m, amin, amax;
    scanf("%d %d", &n, &k);
    char str[9];
    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%s %d %d", str, &rich[i].age, &rich[i].wealth);
        rich[i].name = string(str);
    }
    sort(rich, rich + n, cmp);
    for (int i = 0; i < k; ++i) {
        printf("Case #%d:\n", i + 1);
        scanf("%d %d %d", &m, &amin, &amax);
        bool flag = 0;
        for (int j = 0; j < n; ++j) {
            if (rich[j].age >= amin && rich[j].age <= amax) {
                flag = 1;
                printf("%s %d %d\n", rich[j].name.c_str(), rich[j].age, rich[j].wealth);
                --m;
                if (m == 0) {
                    break;
                }
            }
        }
        if (!flag) {
            printf("None\n");
        }
    }
    return 0;
}