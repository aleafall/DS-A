//
// Created by aleafall on 16-10-25.
//

#include <iostream>

using namespace std;

//class Solution {
//public:
//    int divide(int dividend, int divisor) {
//        long long ans=0;
//        long long a=dividend,b=divisor;
//        bool flag=0;
//        if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
//            flag=1;
//        }
//        if (a<0) a=-a;
//        if (b<0) b=-b;
////        cout<<"a b "<<a<<" "<<b<<endl;
//        while (a >= b) {
//            int i=1;
//            long long temp=b;
//            for (; temp <= a; ++i) {
//                temp<<=1;
//            }
////            cout<<"before "<<ans<<endl;
//            ans += (1 << (i - 2));
//            a -= b << (i - 2);
////            cout<<"i "<<i<<endl;
////            cout<<"in "<<ans<<endl;
//        }
////        cout<<"ans "<<ans<<endl;
//        if (flag) ans=-ans;
//        if (ans>INT32_MAX||ans<=INT32_MIN) return INT32_MAX;
//        return (int) ans;
//    }
//};
class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int divd = dividend, divs = divisor;//使用unsigned防止-2147483648符号取反后溢出
        if(divisor < 0)divs = -divs;//负数全部转化为正数
        if(dividend < 0)divd = -divd;

        int res = 0;
        while(divd >= divs)
        {
            long long a = divs;//使用long long防止移位溢出
            int i;
            for(i = 1; a <= divd; i++)
                a <<= 1;
            res += (1 << (i-2));
            divd -= (divs << (i-2));
        }

        return (dividend>0 ^ divisor>0) ? -res : res;
    }
};

int main(){
    Solution *solution=new Solution;
    cout<<solution->divide(-2147483648 ,-1)<<endl;
    delete solution;
    return 0;
}
