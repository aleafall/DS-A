//
// Created by t-xiuyan on 7/8/2017.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LogSystem {
	unordered_map<string,int> time2id,granu2id;
	vector<string> granu{"Year", "Month", "Day", "Hour", "Minute", "Second"};
public:
	LogSystem() {
		for (int i = 0; i < granu.size(); ++i) {
			granu2id[granu[i]] = i;
		}
	}

	void put(int id, string timestamp) {
		time2id[timestamp] = id;
	}

	vector<int> retrieve(string s, string e, string gra) {
		vector<int> ans;
		int len = 3 * granu2id[gra] + 4;
		string start = s.substr(0, len), end = e.substr(0, len);
		for (auto &&item :time2id) {
			if (item.first.substr(0, len) >= start && item.first.substr(0, len) <= end) {
				ans.push_back(item.second);
			}
		}
		return ans;

	}
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
