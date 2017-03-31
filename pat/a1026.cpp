//
// Created by aleafall on 16-11-23.
//

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int maxm = 101;
const int inf = 0x3fffffff;

struct Player {
    int arrive, start, dur;
    bool isVip;
};

struct Table {
    int start, cnt;
    bool isVip;

    Table() : start(8 * 3600), cnt(0), isVip(0) {}
} table[maxm];

bool cmp(Player a, Player b) {
    return a.arrive < b.arrive;
}

int main() {
    int beginTime = 8 * 3600, endTime = 21 * 3600;
    int n, hh, mm, ss, t, k, m, x, d;
    scanf("%d", &n);
    vector<Player> players(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &t, &d);
        players[i].isVip = d;
        players[i].dur = t * 60 > 7200 ? 7200 : t * 60;
        players[i].arrive = hh * 3600 + mm * 60 + ss;
    }
    scanf("%d %d", &k, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        table[x - 1].isVip = 1;
    }
    int index = 0;
    sort(players.begin(), players.end(), cmp);
    for (int i = 0; i < n; ++i) {
        int u = -1, Min = inf;
        for (int j = 0; j < k; ++j) {
            if (table[j].start < Min) {
                u = j;
                Min = table[j].start;
            }
        }
        if (Min >= endTime || players[i].arrive >= endTime) {
            players.resize(i);
            break;
        }
        while (index < n && players[index].arrive <= Min) {
            ++index;
        }
        if (table[u].isVip) {
            int vipPos = i;
            for (int j = i; j < index; ++j) {
                if (players[j].isVip) {
                    vipPos = j;
                    break;
                }
            }
            Player temp = players[vipPos];
            for (int j = vipPos - 1; j >= i; --j) {
                players[j + 1] = players[j];
            }
            players[i] = temp;
        }
        if (players[i].isVip && !table[u].isVip) {
            for (int j = 0; j < k; ++j) {
                if (table[j].isVip && table[j].start <= players[i].arrive) {
                    u = j;
                    break;
                }
            }
        }
        players[i].start = max(table[u].start, players[i].arrive);
        table[u].start = players[i].start + players[i].dur;
        table[u].cnt++;
    }
    for (int i = 0; i < players.size(); ++i) {
        printf("%02d:%02d:%02d ", players[i].arrive / 3600, players[i].arrive % 3600 / 60, players[i].arrive % 60);
        printf("%02d:%02d:%02d ", players[i].start / 3600, players[i].start % 3600 / 60, players[i].start % 60);
        printf("%d\n",
               (players[i].start - players[i].arrive) / 60 + ((players[i].start - players[i].arrive) % 60 + 30) / 60);
    }
    for (int i = 0; i < k; ++i) {
        if (i < k - 1) {
            printf("%d ", table[i].cnt);
        } else {
            printf("%d\n", table[i].cnt);
        }
    }
    return 0;
}
