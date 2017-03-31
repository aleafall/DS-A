//
// Created by aleafall on 16-10-23.
//

#include <iostream>

using namespace std;

int main(){
    long long sum=0;
    int a,b=1;
    cin>>a;
    if (a>b) swap(a, b);
    for (int i = a; i <=b ; ++i) {
        sum+=i;
    }
    cout<<sum<<endl;
    return 0;
}
