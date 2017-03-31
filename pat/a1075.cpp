//
// Created by aleafall on 16-11-30.
//

#include <iostream>
#include "algorithm"

using namespace std;

const int maxn = 10005;

struct Stu {
    int id, score[5],total=0;
    int Rank, perfect = 0;
    bool flag = 0;
} stu[maxn];

bool cmp(Stu a,Stu b){
    if (a.flag != b.flag) {
        return a.flag > b.flag;
    } else if (a.score != b.score) {
        return a.score > b.score;
    } else if (a.perfect != b.perfect) {
        return a.perfect > b.perfect;
    }
    return a.id < b.id;
}

int main(){
    int toll[5];
    int n,k,m, uid, pid, pscore, cnt = 0;
    cin >> n >> k >> m;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &toll[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &uid, &pid, &pscore);
        if (pscore >0) {
            stu[uid].flag = 1;
            if (pscore > stu[uid].score[pid]) {
                stu[uid].total += (pscore - stu[uid].score[pid]);
            }
            if (stu[uid].score[pid] == -1) {
                stu[uid].total--;
            }
            stu[uid].score[pid] = pscore;
            if (pscore == toll[pid]) {
                stu[uid].perfect++;
            }
        } else if (pscore == 0) {
            stu[uid].score[pid] = -1;
            stu[uid].flag = 1;
        }
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; ++i) {
        if (i && stu[i].total == stu[i - 1].total) {
            stu[i].Rank = stu[i - 1].Rank;
        } else {
            stu[i].Rank = i + 1;
        }
        if (stu[i].flag) {
            printf("%d %05d %d ", stu[i].Rank, stu[i].id, stu[i].total);
            for (int j = 0; j < k; ++j) {
                if (stu[i].score[j] != -1) {
                    printf("%d", stu[i].score[j]);
                } else {
                    printf("-");
                }
                if (j < k - 1) {
                    printf(" ");
                } else {
                    printf("\n");
                }
            }
        } else {
            break;
        }
    }
    return 0;
}
