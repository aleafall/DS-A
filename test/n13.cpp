//
// Created by aleafall on 17-3-17.
//

#include <iostream>
#include <queue>

using namespace std;

const int maxn = 10;

int m, n, bx, by, px, py, ex, ey;
char maze[maxn][maxn];
int vis[maxn][maxn][maxn][maxn] = {0};
int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};

struct Pave {
	int px, py, bx, by;

	Pave(int x1, int y1, int x2, int y2) : px(x1), py(y1), bx(x2), by(y2) {}
};

int BFS() {
	Pave pave(px, py, bx, by);
	queue<Pave> q;
	vis[px][py][bx][by] = 1;
	q.push(pave);
	while (q.size()) {
		pave = q.front();
		printf("pave %d %d %d %d\n", pave.px, pave.py, pave.bx, pave.by);
		q.pop();
		if (pave.bx == ex && pave.by == ey) {
//			cout << "to early" << endl;
			return vis[pave.px][pave.py][pave.bx][pave.by] - 1;
		}
		for (int i = 0; i < 4; ++i) {
			int newX = pave.px + X[i], newY = pave.py + Y[i];
			if (newX < 0 || newX >= m || newY < 0 || newY >= n || maze[newX][newY] == '#') {
				continue;
			}
			if (newX == pave.bx && newY == pave.by) {
				if (newX + X[i] < 0 || newX + X[i] >= m || newY + Y[i] < 0 || newY + Y[i] >= n ||
				    maze[newX + X[i]][newY + Y[i]] == '#' || vis[newX][newY][newX + X[i]][newY + Y[i]]) {
					continue;
				}
				vis[newX][newY][newX + X[i]][newY + Y[i]] = vis[pave.px][pave.py][pave.bx][pave.by] + 1;
				q.push(Pave(newX, newY, newX + X[i], newY + Y[i]));
			} else {
				if (vis[newX][newY][pave.bx][pave.by]) {
					continue;
				}
				vis[newX][newY][pave.bx][pave.by] = vis[pave.px][pave.py][pave.bx][pave.by] + 1;
				q.push(Pave(newX, newY, pave.bx, pave.by));
			}
		}
	}
//	cout << "to late" << endl;
	return -1;
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; ++i) {
		getchar();
		for (int j = 0; j < n; ++j) {
			scanf("%c", &maze[i][j]);
			if (maze[i][j] == '*') {
				bx = i, by = j;
			} else if (maze[i][j] == 'X') {
				px = i, py = j;
			} else if (maze[i][j] == '@') {
				ex = i, ey = j;
			}
		}
	}
	cout << BFS() << endl;
	return 0;
}
