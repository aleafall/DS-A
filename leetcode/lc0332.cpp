//
// Created by t-xiuyan on 8/26/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	vector<string> ans;
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		vector<string> now{"JFK"};
		DFS(now, tickets);
		return ans;
	}
	void DFS(vector<string> now,vector<pair<string,string>> tickets){
		if (tickets.empty()) {
			if (ans.empty()) {
				ans = now;
			} else {
				for (int i = 0; i < now.size(); ++i) {
					if (now[i] < ans[i]) {
						ans = now;
						break;
					}
				}
			}
			return;
		}
		for (int i = 0; i < tickets.size(); ++i) {
			if (tickets[i].first == now.back()) {
				now.push_back(tickets[i].second);
				auto temp = tickets[i];
				swap(tickets[i], tickets.back());
				tickets.pop_back();
				DFS(now, tickets);
				tickets.push_back(temp);
				swap(tickets[i], tickets.back());
				now.pop_back();
			}
		}
	}
};
