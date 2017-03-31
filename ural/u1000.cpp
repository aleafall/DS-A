//
// Created by aleafall on 16-10-3.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int i=0;
    double b,*a=new double[300000];//数组要开的大一些,一开始开小了,就一直卡在一些数据上.
    while(cin>>b)
        a[i++]=b;

    for(i--;i>=0;i--)
        printf("%.4lf\n",sqrt(a[i]));
    delete a;
    return 0;
}
