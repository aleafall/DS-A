//
// Created by aleafall on 16-11-17.
//

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int ans=0;
        int X[4] = {0, 0, - 1, 1};
        int Y[4] = {-1, 1, 0, 0};
        struct Node {
            int x, y;
            Node(){}
            Node(int x,int y):x(x),y(y){}
        } node;
        for (size_t i = 0; i <grid.size() ; ++i) {
            for (size_t j = 0; j <grid[0].size() ; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    ++ans;
                    queue<Node> q;
                    q.push(Node(i, j));
                    while (!q.empty()) {
                        Node root = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            node = Node(root.x + X[k], root.y + Y[k]);
                            if (node.x >= 0 && node.x < grid.size() && node.y >= 0 && node.y < grid[0].size()) {
                                if (grid[node.x][node.y] == '1') {
                                    grid[node.x][node.y] = '0';
                                    q.push(node);
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
