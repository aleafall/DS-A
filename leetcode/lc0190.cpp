//
// Created by aleafall on 16-10-19.
//

#include <iostream>

using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long num=n,ans=0;
        while (n){
            if (n&1) ans=ans*2+1;
            else ans*=2;
            if (n%2) cout<<1;
            else cout<<0;
            n/=2;
        }
        cout<<endl;
        return (uint32_t) ans;
    }
};

int main(){
    Solution *solution=new Solution;
    uint32_t n=43261596;
    cout<<solution->reverseBits(n)<<endl;
    delete solution;
    return 0;
}