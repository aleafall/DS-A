//
// Created by aleafall on 17-10-7.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	string validIPAddress(string IP) {
		if (IP.empty()) {
			return "Neither";
		}
		if (isV4(IP)) {
			return "IPv4";
		}
		if (isV6(IP)) {
			return "IPv6";
		}
		return "Neither";
	}
	bool isV4(string &ip){
		if (ip.back() < '0' || ip.back() > '9') {
			return 0;
		}
		stringstream ss(ip);
		string now;
		int cnt = 0;
		while (getline(ss, now, '.')) {
			++cnt;
			if (now.empty()||(now.size()>1&&now.front()=='0')) {
				return 0;
			}
			int num = 0;
			for (auto &&item :now) {
				if (item < '0' || item > '9') {
					return 0;
				}
				num = num * 10 + item - '0';
				if (num > 255) {
					return 0;
				}
			}
		}
		return cnt == 4;
	}
	bool isV6(string &ip){
		stringstream ss(ip);
		int cnt = 0;
		bool hashTable[256] = {0};
		for (char i = '0'; i <= '9'; ++i) {
			hashTable[i] = 1;
		}
		for (char i = 'a'; i <= 'f'; ++i) {
			hashTable[i] = hashTable[i - 'a' + 'A'] = 1;
		}
		if (!hashTable[ip.back()]) {
			return 0;
		}
		string now;
		while (getline(ss, now, ':')) {
			++cnt;
//			cout << "Now " << now << endl;
			if (now.empty() || now.size() > 4) {
				return 0;
			}
			for (auto &&item :now) {
				if (!hashTable[item]) {
					return 0;
				}
			}
		}
		return cnt == 8;
	}
};

int main() {
	Solution solution;
	string ip = "20EE:Fb8:85a3:0:0:8A2E:0370:7334";
	cout << solution.validIPAddress(ip) << endl;
    return 0;
}
