//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <queue>

using namespace std;

const int maxn = 130, maxm = 1290, maxl = 65;

struct Node {
    int x, y, z;
} node;
int matrix[maxm][maxn][maxl];
bool vis[maxm][maxn][maxl] = {0};
int X[6] = {0, 0, -1, 1, 0, 0};
int Y[6] = {0, 0, 0, 0, -1, 1};
int Z[6] = {-1, 1, 0, 0, 0, 0};

int n, m, l, k;

bool check(int x, int y, int z) {
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) {
        return 0;
    }
    if (vis[x][y][z] || matrix[x][y][z] == 0) {
        return 0;
    }
    return 1;
}

int BFS(int x, int y, int z) {
    int ans = 0;
    queue<Node> q;
    node.x = x, node.y = y, node.z = z;
    vis[node.x][node.y][node.z] = 1;
    q.push(node);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        ++ans;
        for (int i = 0; i < 6; ++i) {
            int newX = node.x + X[i], newY = node.y + Y[i], newZ = node.z + Z[i];
//            Node now;
//            now.x = node.x + X[i], now.y = node.y + Y[i], now.z = node.z + Z[i];
            if (check(newX, newY, newZ)) {
                vis[newX][newY][newZ] = 1;
                Node now;
                now.x = newX, now.y = newY, now.z = newZ;
                q.push(now);
            }
        }
    }
    if (ans >= k) {
        return ans;
    }
    return 0;
}

int main() {
    int ans = 0;
    cin >> m >> n >> l >> k;
    for (int z = 0; z < l; ++z) {
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                scanf("%d", &matrix[x][y][z]);
            }
        }
    }
    for (int z = 0; z < l; ++z) {
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (vis[x][y][z] == 0 && matrix[x][y][z] == 1) {
                    ans += BFS(x, y, z);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
