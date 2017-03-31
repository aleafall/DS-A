//
// Created by aleafall on 16-10-28.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>


using namespace std;

const int maxn = 8;

struct knight {
    int x, y, step;
    int h, g, f;

    bool operator<(const knight &k) const {
        return f > k.f;
    }
} k;

vector<knight> pre(maxn * maxn);
bool vis[maxn][maxn] = {0};
int x1, y1, x2, y2, ans;
int dir[maxn][2] = {{2,  1},
                    {1,  2},
                    {-2, 1},
                    {-1, 2},
                    {2,  -1},
                    {1,  -2},
                    {-2, -1},
                    {-1, -2}};
priority_queue<knight> q;

bool in(const knight &a) {
    if (a.x < 0 || a.x >= maxn || a.y < 0 || a.y >= maxn) {
        return 0;
    }
    return 1;
}

int Heuristic(const knight &a) {
    return 10 * (abs(a.x - x2) + abs(a.y - y2));
}

void Astar() {
    knight temp, next;
    while (!q.empty()) {
        temp = q.top();
        cout << char(temp.x + 'a') << " " << char(temp.y + '1') << endl;
        q.pop();
        vis[temp.x][temp.y] = 1;
        if (temp.x == x2 && temp.y == y2) {
            ans = temp.step;
            cout << "print the pre\n";
            knight now = pre[temp.x * maxn + temp.y];
            while (now.x != x1 || now.y != y1) {
                cout<<char(now.x+'a')<<char(now.y+'1')<< ' ';
                now = pre[now.x * maxn + now.y];
            }
            cout<<endl;
            break;
        }
        for (int i = 0; i < maxn; ++i) {
            next.x = temp.x + dir[i][0];
            next.y = temp.y + dir[i][1];
            if (in(next) && !vis[next.x][next.y]) {
                next.g = temp.g + 23;
                next.h = Heuristic(next);
                next.f = next.h + next.g;
                next.step = temp.step + 1;
                q.push(next);
                pre[next.x*maxn+next.y]=temp;
            }
        }
    }
}

int main() {
    string str;
    while (getline(cin, str)) {
        if (str.empty()) {
            continue;
        }
        x1 = str[0] - 'a';
        y1 = str[1] - '1';
        x2 = str[3] - 'a';
        y2 = str[4] - '1';
        fill(vis[0], vis[0] + maxn * maxn, 0);
        k.x = x1, k.y = y1, k.g = k.step = 0, k.h = Heuristic(k), k.f = k.h + k.g;
        while (!q.empty()) {
            q.pop();
        }
        q.push(k);
        Astar();
        printf("To get from %c%c to %c%c takes %d knight moves.\n", str[0], str[1], str[3], str[4], ans);
    }
    return 0;
}
