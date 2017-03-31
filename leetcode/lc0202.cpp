//
// Created by aleafall on 16-10-18.
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        map<int,int> mp;
        mp[n]=1;
        while (1){
            int now=0;
            while (n){
                int temp=n%10;
                n/=10;
                now+=temp*temp;
            }
            n=now;
            if (mp.find(n)!=mp.end()){
                mp[n]++;
                if (mp[n]>1)
                    return n==1;
            } else mp[n]=1;
        }
        return 0;
    }
};

int main(){
    int n=19;
    Solution *solution=new Solution;
    cout<<solution->isHappy(n)<<endl;
    delete solution;
    return 0;
}
