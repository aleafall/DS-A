/*************************************************************************
    > File Name: a1062.cpp
    > Author: aleafall
    > Mail: atharry@qq.com 
    > Created Time: 2016年11月28日 星期一 19时21分44秒
 ************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=100005;

struct Person {
    int id,v, t, total, flag;
} person[maxn];

bool cmp(Person a,Person b){
    if (a.flag != b.flag) {
        return a.flag < b.flag;
    } else if (a.total != b.total) {
        return a.total > b.total;
    } else if (a.v != b.v) {
        return a.v > b.v;
    } else {
        return a.id < b.id;
    }
}

int main(){
    int n,l,h, m;
    scanf("%d %d %d", &n, &l, &h);
    m = n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &person[i].id, &person[i].v, &person[i].t);
        person[i].total = person[i].v + person[i].t;
        if (person[i].v < l || person[i].t < l) {
            person[i].flag = 5;
            --m;
        } else if (person[i].v >= h && person[i].t >= h) {
            person[i].flag = 1;
        } else if (person[i].v>=h) {
            person[i].flag = 2;
        } else if (person[i].v >= person[i].t) {
            person[i].flag = 3;
        } else {
            person[i].flag = 4;
        }
    }
    sort(person, person + n, cmp);
    printf("%d\n", m);
    for (int i = 0; i < m; ++i) {
        printf("%08d %d %d\n", person[i].id, person[i].v, person[i].t);
    }
    return 0;
}
