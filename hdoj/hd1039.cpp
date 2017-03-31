#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;

bool vovel[256]={0};

bool check(string &s){
	bool flag1=0;
	int cnt1=0,cnt2=0;
	for(int i=0;i<s.size();++i){
		if(flag1==0&&vovel[s[i]]){
			flag1=1;
		}

		if(vovel[s[i]]){
			cnt2=0;
			cnt1++;
			if(i==0) continue;
			if(cnt1==2&&s[i]==s[i-1]){
				if(s[i]!='e'&&s[i]!='o')
					return 0;
			} else if(cnt1>=3) return 0;
		} else {
			cnt1=0;
			cnt2++;
			if(i==0) continue;
			if((cnt2==2&&s[i]==s[i-1])||cnt2>=3){
				return 0;
			}
		}
	}
	return flag1;
}
int main() {
	vovel['a']=1;
	vovel['e']=1;
	vovel['i']=1;
	vovel['o']=1;
	vovel['u']=1;
	string s;
	while(cin>>s){
		if(s=="end") break;
		if(check(s)) printf("<%s> is acceptable.\n",s.c_str());
		else printf("<%s> is not acceptable.\n",s.c_str());	
	}
	system("pause");
    return 0;
}
