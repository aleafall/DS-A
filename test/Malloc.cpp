#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

struct q {

	int x, y, xb, yb;

	q(int x, int y, int xb, int yb) : x(x), y(y), xb(xb), yb(yb) {}

};

int a[] = {0, 0, 1, -1}, b[] = {1, -1, 0, 0};

char mp[10][10];

int vis[10][10][10][10];

int bx, by, sx, sy, ex, ey, n, m;

int bfs() {

	vis[sx][sy][bx][by] = 1;

	q p(sx, sy, bx, by);

	queue<q> que;

	que.push(p);

	while (que.size()) {
		p = que.front();
		printf("pave %d %d %d %d\n", p.x, p.y, p.xb, p.yb);
		que.pop();

		if (p.xb == ex && p.yb == ey)return vis[p.x][p.y][p.xb][p.yb] - 1;

		for (int i = 0; i < 4; i++) {

			int nx = p.x + a[i], ny = p.y + b[i];

			if (nx < 0 || ny < 0 || mp[nx][ny] == '#' || nx >= n || ny >= m)continue;

			if (nx == p.xb && ny == p.yb) {

				if (nx + a[i] < 0 || ny + b[i] < 0 || mp[nx + a[i]][ny + b[i]] == '#' || nx + a[i] >= n ||
				    ny + b[i] >= m)
					continue;

				if (vis[nx][ny][nx + a[i]][ny + b[i]])continue;

				vis[nx][ny][nx + a[i]][ny + b[i]] = vis[p.x][p.y][p.xb][p.yb] + 1;

				que.push(q(nx, ny, nx + a[i], ny + b[i]));

			} else {

				if (vis[nx][ny][p.xb][p.yb])continue;

				vis[nx][ny][p.xb][p.yb] = vis[p.x][p.y][p.xb][p.yb] + 1;

				que.push(q(nx, ny, p.xb, p.yb));

			}

		}

	}

	return -1;

}

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)

		scanf("%s", mp[i]);

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			if (mp[i][j] == '*')bx = i, by = j;

			else if (mp[i][j] == 'X')sx = i, sy = j;

			else if (mp[i][j] == '@')ex = i, ey = j;

	cout << bfs() << endl;

	return 0;

}
