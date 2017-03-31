//
// Created by aleafall on 16-11-23.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int maxn=30001;

struct Stu {
    long long id;
    int score, local_rank, location, final_rank;
} stu[maxn];

bool cmp(Stu a, Stu b){
    if (a.score != b.score) {
        return a.score > b.score;
    } else {
        return a.id < b.id;
    }
}
int main(){
    int n, k, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            scanf("%lld %d", &stu[cnt+j].id, &stu[cnt+j].score);
            stu[cnt+j].location = i + 1;
        }
        sort(stu + cnt, stu + cnt + k, cmp);
        for (int j = 0; j < k; ++j) {
            if (j && stu[cnt + j].score == stu[cnt + j - 1].score) {
                stu[cnt + j].local_rank = stu[cnt+j-1].local_rank;
            } else {
                stu[cnt + j].local_rank = j + 1;
            }
        }
        cnt += k;
    }
    sort(stu, stu + cnt, cmp);
    for (int i = 0; i < cnt; ++i) {
        if (i && stu[i].score == stu[i - 1].score) {
            stu[i].final_rank = stu[i - 1].final_rank;
        } else {
            stu[i].final_rank = i + 1;
        }
    }
    cout<<cnt<<endl;
    for (int i = 0; i < cnt; ++i) {
        printf("%013lld %d %d %d\n", stu[i].id, stu[i].final_rank, stu[i].location, stu[i].local_rank);
    }
    return 0;
}
