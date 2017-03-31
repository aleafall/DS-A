//
// Created by aleafall on 16-10-3.
//

#include <cmath>
#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;
const int maxn=300001;
long long a[maxn];
stack<int> s;

int main(){
    long long x;
    int i=0;
    double d;
    while (cin>>x){
        a[i++]=x;
    }
    for (int j = 0; j < i; ++j) {
        printf("%.4f\n",sqrt(1.0*a[i-1-j]));
    }
    return 0;
}
