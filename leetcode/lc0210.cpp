//
// Created by aleafall on 16-11-20.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        queue<int> q;
        vector<int> ans;
        vector<int> vis((unsigned long) numCourses, 0);
        vector<vector<int>> vi((unsigned long) numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            auto now = prerequisites[i];
            vi[now.second].push_back(now.first);
            vis[now.first]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (vis[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            for (int i = 0; i < vi[next].size(); ++i) {
                vis[vi[next][i]]--;
                if (vis[vi[next][i]] == 0) {
                    q.push(vi[next][i]);
                }
            }
            vi[next].clear();
            ans.push_back(next);
        }
        if(ans.size()==numCourses){
            return ans;
        } else{
            ans.clear();
            return ans;
        }
    }
};