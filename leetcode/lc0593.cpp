//
// Created by aleafall on 17-5-21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		vector<pair<int,int>> v;
		v.push_back(make_pair(p1.front(), p1.back()));
		v.push_back(make_pair(p2.front(), p2.back()));
		v.push_back(make_pair(p3.front(), p3.back()));
		v.push_back(make_pair(p4.front(), p4.back()));
		sort(v.begin(),v.end(),[](const pair<int,int> &a,const pair<int,int> &b)->bool {
			if (a.first != b.first) {
				return a.first < b.first;
			}
			return a.second < b.second;
		});
		double len1 = getLen(v[0], v[1]), len2 = getLen(v[0], v[2]), len3 = getLen(v[3], v[1]), len4 = getLen(v[3],
		                                                                                                      v[2]);
		if (len1 == 0 || len2 == 0 || len3 == 0 || len4 == 0) {
			return 0;
		}
		if (len1 != len2 || len1 != len3 || len1 != len4) {
			return 0;
		}
		double angle = (len1 * len1 + len2 * len2 - getLen(v[1], v[2]) * getLen(v[1], v[2])) / 2 / len1 / len2;
		return angle >= -0.001 && angle <= 0.001;
	}
	double getLen(pair<int,int> &a,pair<int,int> &b){
		int x = a.first - b.first, y = a.second - b.second;
		return sqrt(1.0 * (x * x + y * y));
	}
};
