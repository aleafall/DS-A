//
// Created by aleafall on 16-11-20.
//

#include <iostream>

using namespace std;

int main(){
    int N, pre=0, now, ans = 0;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin >> now;
        if (now > pre) {
            ans += 6 * (now - pre);
        } else {
            ans += 4 * (pre - now);
        }
        ans+=5;
        pre = now;
    }
    cout<<ans<<endl;
    return 0;
}
