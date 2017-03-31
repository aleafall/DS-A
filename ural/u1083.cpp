//
// Created by aleafall on 16-10-23.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int k= (int) s.size();
    int ans=1,end;
    if (n % k) {
        end=n%k;
    } else {
        end=k;
    }
    for (int i = n; i >= end; i-=k) {
       ans*=i;
    }
    cout<<ans<<endl;
    return 0;
}
