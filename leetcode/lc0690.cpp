//
// Created by aleafall on 17-10-3.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Employee info
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

class Solution {
public:
	int getImportance(vector<Employee *> employees, int id) {
		unordered_map<int, Employee *> mp;
		for (auto &&item :employees) {
			mp[item->id] = item;
		}
		int ans = 0;
		DFS(mp[id], ans, mp);
		return ans;
	}

	void DFS(Employee *e, int &ans, unordered_map<int, Employee *> &mp) {
		ans += e->importance;
		for (auto &&item :e->subordinates) {
			DFS(mp[item], ans, mp);
		}
	}
};
