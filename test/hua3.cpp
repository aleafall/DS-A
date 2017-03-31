//
// Created by aleafall on 17-3-3.
//

#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

void ReverseWords(char *s){
	vector<string> vs;
	string str = string(s);
	int i=0;
	for (; i < str.size();) {
		string now;
		while (str[i] == ' ' && i < str.size()) {
			++i;
		}
		while (str[i] != ' ' && i < str.size()) {
			now += str[i++];
		}
		while (str[i] == ' ' && i < str.size()) {
			++i;
		}
//		cout << "now " << now << endl;
		vs.push_back(now);
	}
	reverse(vs.begin(), vs.end());
	string ans;
	for (int j = 0; j < vs.size(); ++j) {
		if (j) {
			ans += " ";
		}
		ans += vs[j];
	}
	int len = strlen(s);
	strcpy(s, ans.c_str());
	if (len >= ans.size()) {
		s[ans.size()]='\0';
	}
}

int main(){
	string s;
	char str[100000];
//	getline(cin, str);
	getline(cin, s);
	strcpy(str, s.c_str());
//	gets(str);
//	scanf("%s", str);
//	gets(str);
	string ref;
//	ReverseWords((char *) s.c_str());
	ReverseWords(str);
	cout << str << endl;
}
