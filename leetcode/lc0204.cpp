//
// Created by aleafall on 16-10-18.
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        bool *check=new bool[n];
        check[2]=0;
        int sqr= (int) sqrt(1.0 * n);
        for (int i = 3; i < n; ++i) {
            if (i&1) check[i]=0;
            else check[i]=1;
        }
        for (int i = 3; i < n; i+=2) {
            if (check[i]==0){
                for (int j = i+i; j <n ; j+=i) {
                    check[j]=1;
                }
            }
        }
        int ans=0;
        for (int i = 2; i < n; ++i) {
            if (check[i]==0){

                ans++;
//                cout<<i<<endl;
            }
        }
        delete[] check;
        return ans;
    }
};

int main(){
    int n=10;
    Solution *solution=new Solution;
    cout<<solution->countPrimes(n)<<endl;
    return 0;
}