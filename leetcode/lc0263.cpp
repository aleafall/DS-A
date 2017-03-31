//
// Created by aleafall on 16-10-18.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num<=0) return 0;
        if (num==1) return 1;
        vector<int> factors;
        int sqr= (int) sqrt(1.0 * num);
        for (int i = 2; i <= sqr && num!=1; ++i) {
            while (num%i==0){
                num/=i;
                if (factors.empty()||factors[factors.size()-1]!=i){
                    factors.push_back(i);
                }
            }
        }
        if (num!=1) factors.push_back(num);
        for (int i = 0; i < factors.size(); ++i) {
            if (factors[i]!=2&&factors[i]!=3&&factors[i]!=5) return 0;
        }
        return 1;
    }
};

int main(){
    int n=14;
    Solution *solution=new Solution;
    cout<<solution->isUgly(n)<<endl;
    delete solution;
    return 0;
}
