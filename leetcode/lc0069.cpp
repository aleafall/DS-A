//
// Created by aleafall on 16-10-18.
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int cnt=10;
        int sqr=(int)sqrt(1.0*x);
        double a=1.0*x/2;
        for (int i = 0; i < cnt*10; ++i) {
            a=(a+1.0*x/a)/2;
        }
        cout<<"moni "<<(int)a<<endl;
        cout<<"real "<<sqr<<endl;
        return (int)a;
    }
};

int main(){
    Solution *solution=new Solution;
    int n=2147395599;
    cout<<solution->mySqrt(n)<<endl;
    delete solution;
    return 0;
}
