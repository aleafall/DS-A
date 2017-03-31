//
// Created by aleafall on 16-9-22.
//

#include <iostream>

using namespace std;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int a,sum=0;
    cin>>a;
    for (int i = 1; i <= a; ++i) {
        if (gcd(i,a)==1) sum++;
    }
    cout<<sum<<endl;
}
