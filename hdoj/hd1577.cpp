/*************************************************************************
    > File Name: hd1577.cpp
    > Author: aleafall
    > Mail: atharry@qq.com 
    > Created Time: 2016年12月09日 星期五 15时24分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}
int main(){
	int L,sx,sy,px,py;
	while(cin>>L){
		if(L==0) break;
		cin>>sx>>sy>>px>>py;
		if(abs(px)>L||abs(py)>L) printf("Out Of Range\n");
		else {
			px=abs(px-sx),py=abs(py-sy);
			if(px==0) printf(py<=1?"Yes\n":"No\n");
			else if(py==0) printf(px<=1?"Yes\n":"No\n");
			else printf(gcd(px,py)==1?"Yes\n":"No\n");
		}
	}
	return 0;
}
